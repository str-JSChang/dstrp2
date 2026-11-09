#include "task1.hpp"
#include "task2.hpp"
using namespace std;

namespace campus {
namespace {
// check the same required fields for registration and editing
bool prepareParcel(Parcel& parcel) {
    parcel.recipientName = trim(parcel.recipientName);
    parcel.recipientId = trim(parcel.recipientId);
    parcel.recipientContact = trim(parcel.recipientContact);
    parcel.deliveryCompany = trim(parcel.deliveryCompany);
    parcel.trackingNumber = trim(parcel.trackingNumber);
    parcel.destination = trim(parcel.destination);
    parcel.parcelType = trim(parcel.parcelType);
    return !parcel.recipientName.empty() && !parcel.recipientId.empty()
        && !parcel.recipientContact.empty() && !parcel.deliveryCompany.empty()
        && !parcel.trackingNumber.empty() && !parcel.destination.empty()
        && !parcel.parcelType.empty();
}

ServiceType routeService(Route route) {
    if (route == Route::Collection) return ServiceType::Collection;
    if (route == Route::CampusDelivery) return ServiceType::CampusDelivery;
    if (route == Route::SpecialHandling) return ServiceType::SpecialHandling;
    return ServiceType::ReturnToSender;
}
}

ParcelRecords::~ParcelRecords() {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

bool ParcelRecords::insert(const Parcel& parcel) {
    if (trim(parcel.id).empty() || find(parcel.id) != nullptr) return false;
    Node* node = new Node{parcel, head};
    head = node;
    return true;
}

Parcel* ParcelRecords::find(const string& id) {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->value.id == id) return &current->value;
    }
    return nullptr;
}

const Parcel* ParcelRecords::find(const string& id) const {
    for (const Node* current = head; current != nullptr; current = current->next) {
        if (current->value.id == id) return &current->value;
    }
    return nullptr;
}

bool ParcelRecords::hasTrackingNumber(const string& tracking, const string& exceptId) const {
    for (const Node* current = head; current != nullptr; current = current->next) {
        if (current->value.trackingNumber == tracking && current->value.id != exceptId) return true;
    }
    return false;
}

bool ParcelRecords::remove(const string& id) {
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

void ParcelRecords::display() const {
    if (head == nullptr) cout << "No parcel records.\n";
    for (const Node* current = head; current != nullptr; current = current->next) {
        printParcel(current->value);
    }
}

IntakeQueue::~IntakeQueue() {
    while (front != nullptr) {
        Node* next = front->next;
        delete front;
        front = next;
    }
    rear = nullptr;
}

bool IntakeQueue::enqueue(const string& id) {
    if (trim(id).empty()) return false;
    Node* node = new Node{id, nullptr};
    if (rear == nullptr) front = node;
    else rear->next = node;
    rear = node;
    return true;
}

bool IntakeQueue::dequeue(string& id) {
    if (front == nullptr) return false;
    id = front->parcelId;
    Node* old = front;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete old;
    return true;
}

bool IntakeQueue::peek(string& id) const {
    if (front == nullptr) return false;
    id = front->parcelId;
    return true;
}

bool IntakeQueue::remove(const string& id) {
    Node* previous = nullptr;
    Node* current = front;
    while (current != nullptr && current->parcelId != id) {
        previous = current;
        current = current->next;
    }
    if (current == nullptr) return false;
    if (previous == nullptr) front = current->next;
    else previous->next = current->next;
    if (current == rear) rear = previous;
    delete current;
    return true;
}

void IntakeQueue::display() const {
    if (front == nullptr) cout << "No parcels waiting.\n";
    for (const Node* current = front; current != nullptr; current = current->next) {
        cout << current->parcelId << '\n';
    }
}

bool ParcelModule::registerParcel(Parcel parcel) {
    if (!prepareParcel(parcel)) {
        cout << "All parcel details are required.\n";
        return false;
    }
    if (records.hasTrackingNumber(parcel.trackingNumber)) {
        cout << "Duplicate tracking number.\n";
        return false;
    }
    parcel.id = "P" + to_string(nextParcelNumber);
    parcel.arrivalTime = currentTimestamp();
    parcel.status = ParcelStatus::Received;
    if (!records.insert(parcel)) return false;
    try {
        waiting.enqueue(parcel.id);
    }
    catch (...) {
        records.remove(parcel.id); // undo registration if the queue could not allocate
        throw;
    }
    nextParcelNumber++;
    cout << "Registered parcel " << parcel.id << ".\n";
    return true;
}

void ParcelModule::displayParcels() const {
    records.display();
}

const Parcel* ParcelModule::findParcel(const string& id) const {
    const Parcel* parcel = records.find(id);
    if (parcel == nullptr) cout << "Parcel not found.\n";
    return parcel;
}

bool ParcelModule::updateParcel(const string& id, Parcel replacement, const ServiceModule& services) {
    Parcel* parcel = records.find(id);
    if (parcel == nullptr || isTerminal(parcel->status)) {
        cout << "Parcel is missing from records or already completed.\n";
        return false;
    }
    if (!prepareParcel(replacement) || records.hasTrackingNumber(replacement.trackingNumber, id)) {
        cout << "Incomplete details or duplicate tracking number.\n";
        return false;
    }
    if (services.hasActiveRequestForParcel(id)) {
        cout << "Finish or cancel the active request before editing parcel details.\n";
        return false;
    }
    replacement.id = parcel->id;
    replacement.arrivalTime = parcel->arrivalTime;
    replacement.status = parcel->status;
    swap(*parcel, replacement);
    cout << "Parcel details updated.\n";
    return true;
}

bool ParcelModule::removeParcel(const string& id, const ServiceModule& services) {
    const Parcel* parcel = records.find(id);
    if (parcel == nullptr || parcel->status != ParcelStatus::Cancelled
        || services.hasActiveRequestForParcel(id)) {
        cout << "Only cancelled parcels without active requests can be removed.\n";
        return false;
    }
    waiting.remove(id);
    return records.remove(id);
}

bool ParcelModule::processNext(Route route, ServiceModule& services, RequestPriority priority) {
    if (route < Route::Collection || route > Route::InvestigationHold
        || (priority != RequestPriority::Urgent && priority != RequestPriority::Normal)) {
        cout << "Invalid route or priority.\n";
        return false;
    }
    string id;
    while (waiting.peek(id)) {
        Parcel* parcel = records.find(id);
        if (parcel != nullptr && parcel->status == ParcelStatus::Received) break;
        waiting.dequeue(id); // discard stale entries without touching parcel records
    }
    if (waiting.empty()) {
        cout << "Intake queue is empty.\n";
        return false;
    }
    if (route == Route::InvestigationHold) return updateStatus(id, ParcelStatus::OnHold, services);
    ServiceRequest request;
    request.parcelId = id;
    request.recipientId = records.find(id)->recipientId;
    request.type = routeService(route);
    request.priority = priority;
    request.serviceDetails = "Routed from intake";
    return services.createRequest(request); // also updates parcel status and removes its waiting ID
}

bool ParcelModule::resumeParcel(const string& id, Route route, ServiceModule& services,
                                RequestPriority priority) {
    const Parcel* parcel = records.find(id);
    if (parcel == nullptr || parcel->status != ParcelStatus::OnHold
        || route < Route::Collection || route > Route::ReturnToSender) {
        cout << "Resume an On hold parcel with a service route. Recover missing parcels to On hold first.\n";
        return false;
    }
    ServiceRequest request;
    request.parcelId = id;
    request.recipientId = parcel->recipientId;
    request.type = routeService(route);
    request.priority = priority;
    request.serviceDetails = "Resumed after staff review";
    return services.createRequest(request);
}

bool ParcelModule::updateStatus(const string& id, ParcelStatus status, const ServiceModule& services) {
    Parcel* parcel = records.find(id);
    if (parcel == nullptr || isTerminal(parcel->status)
        || services.hasActiveRequestForParcel(id)
        || (status != ParcelStatus::Missing && status != ParcelStatus::OnHold
            && status != ParcelStatus::Cancelled)) {
        cout << "Invalid status change. Active requests must be resolved first.\n";
        return false;
    }
    parcel->status = status;
    waiting.remove(id);
    cout << "Parcel status: " << toString(status) << '\n';
    return true;
}

void ParcelModule::displayWaiting() const {
    waiting.display();
}

} // namespace campus
