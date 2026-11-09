#ifndef TASK3_HPP
#define TASK3_HPP

#include "models.hpp"
using namespace std;

namespace campus {
class ServiceModule;

// Task 3 - repeat allocation from the node after the last selection
class ResourceRing {
public:
    ResourceRing() = default;
    ~ResourceRing();
    ResourceRing(const ResourceRing&) = delete;
    ResourceRing& operator=(const ResourceRing&) = delete;
    bool insert(const Resource& resource);
    Resource* find(const string& id);
    const Resource* find(const string& id) const;
    Resource* nextAvailable(ResourceType type);
    void display() const;
private:
    struct Node {
        Resource value;
        Node* next = nullptr;
    };
    Node* tail = nullptr;
    Node* allocationCursor[2] = {nullptr, nullptr};
};

class ResourceModule {
public:
    explicit ResourceModule(ServiceModule& services) : services(services) {}
    bool registerResource(Resource resource);
    bool updateResourceDetails(const string& id, const string& name);
    void displayAvailability() const;
    const Resource* findResource(const string& id) const;
    bool assignRequest(const string& id, ResourceType type);
    bool releaseResource(const string& id);
    bool updateStatus(const string& id, ResourceStatus status);
private:
    friend class ServiceModule;
    bool canReleaseRequest(const string& id) const;
    bool releaseForRequest(const string& id);
    ServiceModule& services;
    ResourceRing resources;
};

} // namespace campus
#endif
