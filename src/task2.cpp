#include "task2.hpp"
#include "task1.hpp"
#include "task3.hpp"
using namespace std;

namespace campus {

RequestQueue::~RequestQueue() {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

bool RequestQueue::insert(const ServiceRequest& request) {
    if (trim(request.id).empty() || find(request.id) != nullptr) return false;
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        bool earlierPriority = current->value.priority < request.priority;
        bool earlierSequence = current->value.priority == request.priority
            && current->value.sequence <= request.sequence;
        if (!earlierPriority && !earlierSequence) break;
        previous = current;
        current = current->next;
    }
    Node* node = new Node{request, current};
    if (previous == nullptr) head = node;
    else previous->next = node;
    return true;
}

ServiceRequest* RequestQueue::find(const string& id) {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->value.id == id) return &current->value;
    }
    return nullptr;
}

const ServiceRequest* RequestQueue::find(const string& id) const {
    for (const Node* current = head; current != nullptr; current = current->next) {
        if (current->value.id == id) return &current->value;
    }
    return nullptr;
}

const ServiceRequest* RequestQueue::nextPending() const {
    for (const Node* current = head; current != nullptr; current = current->next) {
        if (current->value.status == RequestStatus::Pending) return &current->value;
    }
    return nullptr;
}

bool RequestQueue::remove(const string& id) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr && current->value.id != id) {
        previous = current;
        current = current->next;
    }
    if (current == nullptr) return false;
    if (previous == nullptr) head = current->next;
    else previous->next = current->next;
    delete current;
    return true;
}

bool RequestQueue::hasActiveForParcel(const string& id) const {
    for (const Node* current = head; current != nullptr; current = current->next) {
        if (current->value.parcelId == id && isActive(current->value.status)) return true;
    }
    return false;
}

void RequestQueue::displayActive() const {
    bool found = false;
    for (const Node* current = head; current != nullptr; current = current->next) {
        if (isActive(current->value.status)) {
            printRequest(current->value);
            found = true;
        }
    }
    if (!found) cout << "No active service requests.\n";
}

bool ServiceModule::createRequest(ServiceRequest request) {
    request.parcelId = trim(request.parcelId);
    request.recipientId = trim(request.recipientId);
    request.serviceDetails = trim(request.serviceDetails);
    Parcel* parcel = parcels.records.find(request.parcelId);
    if (parcel == nullptr || request.recipientId.empty() || request.recipientId != parcel->recipientId
        || request.serviceDetails.empty() || !validService(request.type)
        || (request.priority != RequestPriority::Urgent && request.priority != RequestPriority::Normal)
        || requests.hasActiveForParcel(request.parcelId)) {
        cout << "Invalid parcel, recipient, service details, priority, or duplicate active request.\n";
        return false;
    }
    if (isTerminal(parcel->status) || parcel->status == ParcelStatus::Missing
        || (parcel->status != ParcelStatus::Received && parcel->status != ParcelStatus::OnHold
            && parcel->status != serviceStatus(request.type))) {
        cout << "Parcel status does not allow this service.\n";
        return false;
    }
    request.id = "R" + to_string(nextRequestNumber);
    request.createdAt = currentTimestamp();
    request.sequence = nextSequence;
    request.status = RequestStatus::Pending;
    request.resourceId.clear();
    request.outcomeDetails.clear();
    if (!requests.insert(request)) return false;
    // insertion is the last allocating operation; commit the parcel after it succeeds
    parcel->status = serviceStatus(request.type);
    parcels.waiting.remove(request.parcelId);
    nextRequestNumber++;
    nextSequence++;
    cout << "Created request " << request.id << ".\n";
    return true;
}

void ServiceModule::displayActiveRequests() const {
    requests.displayActive();
}

const ServiceRequest* ServiceModule::findRequest(const string& id) const {
    const ServiceRequest* request = requests.find(id);
    if (request == nullptr) cout << "Request not found.\n";
    return request;
}

const ServiceRequest* ServiceModule::nextRequest() const {
    const ServiceRequest* request = requests.nextPending();
    if (request == nullptr) cout << "No pending request.\n";
    return request;
}

bool ServiceModule::parcelMatches(const ServiceRequest& request) const {
    const Parcel* parcel = parcels.records.find(request.parcelId);
    return parcel != nullptr && validService(request.type)
        && parcel->recipientId == request.recipientId && parcel->status == serviceStatus(request.type);
}

bool ServiceModule::processRequest(const string& id) {
    ServiceRequest* request = requests.find(id);
    if (request == nullptr || request->status != RequestStatus::Assigned
        || request->resourceId.empty() || !parcelMatches(*request)) {
        cout << "Request must have a matching parcel and assigned resource.\n";
        return false;
    }
    request->status = RequestStatus::InProgress;
    cout << "Request is now in progress.\n";
    return true;
}

bool ServiceModule::completeRequest(const string& id, RequestStatus outcome, const string& details,
                                    const string& recipientId, ResourceModule& resources) {
    ServiceRequest* request = requests.find(id);
    string savedDetails = trim(details);
    if (request == nullptr || request->status != RequestStatus::InProgress
        || (outcome != RequestStatus::Completed && outcome != RequestStatus::Returned)
        || savedDetails.empty() || trim(recipientId) != request->recipientId
        || !parcelMatches(*request) || !resources.canReleaseRequest(id)) {
        cout << "Completion rejected: check processing state, recipient, details and assignment.\n";
        return false;
    }
    Parcel* parcel = parcels.records.find(request->parcelId);
    ParcelStatus target = ParcelStatus::OnHold;
    // finishing a return service always means Returned, even if staff chose Completed
    if (outcome == RequestStatus::Returned || request->type == ServiceType::ReturnToSender) {
        target = ParcelStatus::Returned;
        outcome = RequestStatus::Returned;
    }
    else if (request->type == ServiceType::Collection) target = ParcelStatus::Collected;
    else if (request->type == ServiceType::CampusDelivery || request->type == ServiceType::Redelivery)
        target = ParcelStatus::Delivered;
    // every validation and string allocation happens before changing the three records
    if (!resources.releaseForRequest(id)) return false;
    parcel->status = target;
    request->status = outcome;
    request->outcomeDetails.swap(savedDetails);
    cout << "Request finished. Parcel status: " << toString(target) << '\n';
    return true;
}

bool ServiceModule::cancelRequest(const string& id, ResourceModule& resources) {
    ServiceRequest* request = requests.find(id);
    if (request == nullptr || !isActive(request->status) || !parcelMatches(*request)
        || !resources.canReleaseRequest(id)) {
        cout << "Request cannot be cancelled.\n";
        return false;
    }
    string details = "Cancelled by staff";
    Parcel* parcel = parcels.records.find(request->parcelId);
    if (!resources.releaseForRequest(id)) return false;
    parcel->status = ParcelStatus::Cancelled;
    request->status = RequestStatus::Cancelled;
    request->outcomeDetails.swap(details);
    cout << "Request and parcel cancelled.\n";
    return true;
}

bool ServiceModule::interruptRequest(const string& id, ParcelStatus status, ResourceModule& resources) {
    ServiceRequest* request = requests.find(id);
    if (request == nullptr || !isActive(request->status) || !parcelMatches(*request)
        || (status != ParcelStatus::Missing && status != ParcelStatus::OnHold)
        || !resources.canReleaseRequest(id)) {
        cout << "Request cannot be interrupted with this parcel status.\n";
        return false;
    }
    string details = status == ParcelStatus::Missing ? "Stopped: parcel missing" : "Stopped: investigation hold";
    Parcel* parcel = parcels.records.find(request->parcelId);
    if (!resources.releaseForRequest(id)) return false;
    parcel->status = status;
    request->status = RequestStatus::Cancelled;
    request->outcomeDetails.swap(details);
    cout << "Request stopped. Parcel status: " << toString(status) << '\n';
    return true;
}

bool ServiceModule::removeTerminalRequest(const string& id) {
    const ServiceRequest* request = requests.find(id);
    if (request == nullptr || isActive(request->status) || !request->resourceId.empty()) {
        cout << "Only terminal, unassigned requests can be removed.\n";
        return false;
    }
    return requests.remove(id);
}

bool ServiceModule::hasActiveRequestForParcel(const string& id) const {
    return requests.hasActiveForParcel(id);
}

bool ServiceModule::attachResource(const string& id, const string& resourceId) {
    ServiceRequest* request = requests.find(id);
    if (request == nullptr || request->status != RequestStatus::Pending
        || !request->resourceId.empty() || resourceId.empty() || !parcelMatches(*request)) return false;
    request->resourceId = resourceId;
    request->status = RequestStatus::Assigned;
    return true;
}

bool ServiceModule::detachResource(const string& id) {
    ServiceRequest* request = requests.find(id);
    if (request == nullptr || (request->status != RequestStatus::Assigned
        && request->status != RequestStatus::InProgress)) return false;
    request->resourceId.clear();
    request->status = RequestStatus::Pending;
    return true;
}

} // namespace campus
