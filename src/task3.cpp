#include "task3.hpp"
#include "scaffold.hpp"
#include "task2.hpp"

namespace campus {

ResourceRing::~ResourceRing() {
    if (tail_) {
        Node* current = tail_->next;
        tail_->next = nullptr; // Break the ring before deleting nodes.
        while (current) {
            Node* old = current;
            current = current->next;
            delete old;
        }
    }
    tail_ = nullptr;
    cursor_ = nullptr;
}

// TODO: Implement circular linked-list operations, including one-node rings.
bool ResourceRing::insert(const Resource&) { notImplemented("Insert resource into ring"); return false; }
Resource* ResourceRing::find(const std::string&) { notImplemented("Find resource"); return nullptr; }
const Resource* ResourceRing::find(const std::string&) const { notImplemented("Find resource"); return nullptr; }

// TODO: Inspect at most one full cycle; skip occupied/unavailable/wrong-type
// resources and advance the allocation cursor after a successful selection.
Resource* ResourceRing::nextAvailable(ResourceType) { notImplemented("Select available resource"); return nullptr; }
void ResourceRing::display() const { notImplemented("Display resource ring"); }

bool ResourceModule::registerResource(Resource) { notImplemented("Register resource"); return false; }
bool ResourceModule::updateResourceDetails(const std::string&, const std::string&) { notImplemented("Update resource details"); return false; }
void ResourceModule::displayAvailability() const { notImplemented("Display resource availability"); }

// TODO: Validate request/type compatibility; collection uses counters, delivery
// and redelivery use delivery personnel. For special handling/returns, reject
// allocation until the team's handling rule is defined. Prevent double assignment.
// Call services_.attachResource and commit both sides together, rolling back on failure.
bool ResourceModule::assignRequest(const std::string&, ResourceType) { notImplemented("Assign resource"); return false; }
bool ResourceModule::releaseResource(const std::string&) { notImplemented("Release resource"); return false; }

// TODO: Occupied requires a valid assignment. Becoming unavailable must detach
// any active request and return it to pending before clearing the assignment.
bool ResourceModule::updateStatus(const std::string&, ResourceStatus) { notImplemented("Update resource status"); return false; }
bool ResourceModule::releaseForRequest(const std::string&) { notImplemented("Release request resource"); return false; }

} // namespace campus
