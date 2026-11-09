#ifndef TASK2_HPP
#define TASK2_HPP

#include "models.hpp"
using namespace std;

namespace campus {
class ParcelModule;
class ResourceModule;

// Task 2 - urgent first, then arrival sequence within the same priority
class RequestQueue {
public:
    RequestQueue() = default;
    ~RequestQueue();
    RequestQueue(const RequestQueue&) = delete;
    RequestQueue& operator=(const RequestQueue&) = delete;
    bool insert(const ServiceRequest& request);
    ServiceRequest* find(const string& id);
    const ServiceRequest* find(const string& id) const;
    const ServiceRequest* nextPending() const;
    bool remove(const string& id);
    bool hasActiveForParcel(const string& id) const;
    void displayActive() const;
private:
    struct Node {
        ServiceRequest value;
        Node* next = nullptr;
    };
    Node* head = nullptr;
};

class ServiceModule {
public:
    explicit ServiceModule(ParcelModule& parcels) : parcels(parcels) {}
    bool createRequest(ServiceRequest request);
    void displayActiveRequests() const;
    const ServiceRequest* findRequest(const string& id) const;
    const ServiceRequest* nextRequest() const;
    bool processRequest(const string& id);
    bool completeRequest(const string& id, RequestStatus outcome, const string& details,
                         const string& recipientId, ResourceModule& resources);
    bool cancelRequest(const string& id, ResourceModule& resources);
    bool interruptRequest(const string& id, ParcelStatus status, ResourceModule& resources);
    bool removeTerminalRequest(const string& id);
    bool hasActiveRequestForParcel(const string& id) const;
private:
    friend class ResourceModule; // only resource allocation can attach a resource
    bool attachResource(const string& id, const string& resourceId);
    bool detachResource(const string& id);
    bool parcelMatches(const ServiceRequest& request) const;
    ParcelModule& parcels;
    RequestQueue requests;
    unsigned long long nextRequestNumber = 1;
    unsigned long long nextSequence = 1;
};

} // namespace campus
#endif
