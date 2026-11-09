#include "task3.hpp"
#include "task2.hpp"
using namespace std;

namespace campus {

ResourceRing::~ResourceRing() {
    if (tail != nullptr) {
        Node* current = tail->next;
        tail->next = nullptr; // break the circle so the normal delete loop can finish
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    tail = nullptr;
    allocationCursor[0] = nullptr;
    allocationCursor[1] = nullptr;
}

bool ResourceRing::insert(const Resource& resource) {
    if (trim(resource.id).empty() || find(resource.id) != nullptr) return false;
    Node* node = new Node{resource, nullptr};
    if (tail == nullptr) {
        node->next = node;
        allocationCursor[0] = node;
        allocationCursor[1] = node;
    }
    else {
        node->next = tail->next;
        tail->next = node;
    }
    tail = node;
    return true;
}

Resource* ResourceRing::find(const string& id) {
    if (tail == nullptr) return nullptr;
    Node* current = tail->next;
    do {
        if (current->value.id == id) return &current->value;
        current = current->next;
    } while (current != tail->next);
    return nullptr;
}

const Resource* ResourceRing::find(const string& id) const {
    if (tail == nullptr) return nullptr;
    const Node* current = tail->next;
    do {
        if (current->value.id == id) return &current->value;
        current = current->next;
    } while (current != tail->next);
    return nullptr;
}

Resource* ResourceRing::nextAvailable(ResourceType type) {
    if (tail == nullptr || (type != ResourceType::CollectionCounter
        && type != ResourceType::DeliveryPersonnel)) return nullptr;
    int index = type == ResourceType::CollectionCounter ? 0 : 1;
    Node* start = allocationCursor[index];
    Node* current = start;
    do {
        if (current->value.type == type && current->value.status == ResourceStatus::Available) {
            allocationCursor[index] = current->next;
            return &current->value;
        }
        current = current->next;
    } while (current != start);
    return nullptr; // one full cycle checked, so do not loop forever
}

void ResourceRing::display() const {
    if (tail == nullptr) {
        cout << "No resources registered.\n";
        return;
    }
    const Node* current = tail->next;
    do {
        const Resource& resource = current->value;
        cout << resource.id << " | " << resource.name << " | "
             << (resource.type == ResourceType::CollectionCounter ? "Counter" : "Delivery personnel")
             << " | " << toString(resource.status) << " | request "
             << (resource.assignedRequestId.empty() ? "-" : resource.assignedRequestId) << '\n';
        current = current->next;
    } while (current != tail->next);
}

bool ResourceModule::registerResource(Resource resource) {
    resource.id = trim(resource.id);
    resource.name = trim(resource.name);
    if (resource.id.empty() || resource.name.empty() || resources.find(resource.id) != nullptr
        || (resource.type != ResourceType::CollectionCounter && resource.type != ResourceType::DeliveryPersonnel)) {
        cout << "Resource needs a unique ID, name and valid type.\n";
        return false;
    }
    resource.status = ResourceStatus::Available;
    resource.assignedRequestId.clear();
    return resources.insert(resource);
}

bool ResourceModule::updateResourceDetails(const string& id, const string& name) {
    Resource* resource = resources.find(id);
    string cleanName = trim(name);
    if (resource == nullptr || cleanName.empty()) {
        cout << "Invalid resource or name.\n";
        return false;
    }
    resource->name.swap(cleanName);
    return true;
}

void ResourceModule::displayAvailability() const {
    resources.display();
}

const Resource* ResourceModule::findResource(const string& id) const {
    const Resource* resource = resources.find(id);
    if (resource == nullptr) cout << "Resource not found.\n";
    return resource;
}

bool ResourceModule::assignRequest(const string& id, ResourceType type) {
    const ServiceRequest* request = services.findRequest(id);
    if (request == nullptr || request->status != RequestStatus::Pending
        || !request->resourceId.empty() || !services.parcelMatches(*request)
        || type != serviceResource(request->type)) {
        cout << "Invalid request state or incompatible resource type.\n";
        return false;
    }
    string requestId = request->id;
    Resource* resource = resources.nextAvailable(type);
    if (resource == nullptr) {
        cout << "No suitable resource is available.\n";
        return false;
    }
    if (!services.attachResource(id, resource->id)) return false;
    resource->assignedRequestId.swap(requestId);
    resource->status = ResourceStatus::Occupied;
    cout << "Assigned resource " << resource->id << " to request " << id << ".\n";
    return true;
}

bool ResourceModule::canReleaseRequest(const string& id) const {
    const ServiceRequest* request = services.findRequest(id);
    if (request == nullptr) return false;
    if (request->resourceId.empty()) return request->status == RequestStatus::Pending;
    const Resource* resource = resources.find(request->resourceId);
    return resource != nullptr && resource->status == ResourceStatus::Occupied
        && resource->assignedRequestId == id && resource->type == serviceResource(request->type)
        && (request->status == RequestStatus::Assigned || request->status == RequestStatus::InProgress);
}

bool ResourceModule::releaseForRequest(const string& id) {
    if (!canReleaseRequest(id)) return false;
    const ServiceRequest* request = services.findRequest(id);
    if (request->resourceId.empty()) return true; // cancelling a pending request needs no resource
    Resource* resource = resources.find(request->resourceId);
    if (!services.detachResource(id)) return false;
    resource->assignedRequestId.clear();
    resource->status = ResourceStatus::Available;
    return true;
}

bool ResourceModule::releaseResource(const string& id) {
    Resource* resource = resources.find(id);
    if (resource == nullptr || resource->status != ResourceStatus::Occupied
        || resource->assignedRequestId.empty()) {
        cout << "Resource is invalid or has no active assignment.\n";
        return false;
    }
    string requestId = resource->assignedRequestId;
    return releaseForRequest(requestId);
}

bool ResourceModule::updateStatus(const string& id, ResourceStatus status) {
    Resource* resource = resources.find(id);
    if (resource == nullptr || (status != ResourceStatus::Available && status != ResourceStatus::Occupied
        && status != ResourceStatus::Unavailable)) {
        cout << "Invalid resource or status.\n";
        return false;
    }
    if (status == ResourceStatus::Occupied) {
        if (resource->status == ResourceStatus::Occupied && canReleaseRequest(resource->assignedRequestId)) return true;
        cout << "Assign a request before marking a resource occupied.\n";
        return false;
    }
    if (resource->status == ResourceStatus::Occupied && !releaseResource(id)) return false;
    resource->status = status;
    return true;
}

} // namespace campus
