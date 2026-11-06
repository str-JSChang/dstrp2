#pragma once

#include "models.hpp"

namespace campus {

class ServiceModule;

// Member 3: ring with a rotating allocation cursor for round-robin selection.
class ResourceRing {
public:
    ResourceRing() = default;
    ~ResourceRing();
    ResourceRing(const ResourceRing&) = delete;
    ResourceRing& operator=(const ResourceRing&) = delete;

    bool insert(const Resource& resource);
    Resource* find(const std::string& resourceId);
    const Resource* find(const std::string& resourceId) const;
    Resource* nextAvailable(ResourceType type); // Advance cursor only on selection.
    void display() const;

private:
    struct Node { Resource value; Node* next{nullptr}; };
    Node* tail_{nullptr}; // A nonempty ring has tail_->next as its first node.
    Node* cursor_{nullptr};
};

class ResourceModule {
public:
    explicit ResourceModule(ServiceModule& services) : services_(services) {}

    bool registerResource(Resource resource);
    bool updateResourceDetails(const std::string& resourceId, const std::string& name);
    void displayAvailability() const;
    bool assignRequest(const std::string& requestId, ResourceType requiredType);
    bool releaseResource(const std::string& resourceId);
    bool updateStatus(const std::string& resourceId, ResourceStatus status);
    bool releaseForRequest(const std::string& requestId); // Completion/cancellation hook.

private:
    ServiceModule& services_;
    ResourceRing resources_;
};

} // namespace campus
