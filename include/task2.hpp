#pragma once

#include "models.hpp"

namespace campus {

class ParcelModule;
class ResourceModule;

// Member 2: sorted linked priority queue. Urgent first; equal priority uses FIFO.
// Keep terminal records until explicit removal so repeated processing can be rejected.
// nextPending skips terminal records; displayActive only displays active requests.
class RequestQueue {
public:
    RequestQueue() = default;
    ~RequestQueue();
    RequestQueue(const RequestQueue&) = delete;
    RequestQueue& operator=(const RequestQueue&) = delete;

    bool insert(const ServiceRequest& request);
    ServiceRequest* find(const std::string& requestId);
    const ServiceRequest* find(const std::string& requestId) const;
    const ServiceRequest* nextPending() const;
    bool remove(const std::string& requestId);
    bool hasActiveForParcel(const std::string& parcelId) const;
    void displayActive() const;

private:
    struct Node { ServiceRequest value; Node* next{nullptr}; };
    Node* head_{nullptr};
};

class ServiceModule {
public:
    explicit ServiceModule(ParcelModule& parcels) : parcels_(parcels) {}

    bool createRequest(ServiceRequest request); // Generate ID/time/sequence; validate parcel.
    void displayActiveRequests() const;
    const ServiceRequest* findRequest(const std::string& requestId) const;
    const ServiceRequest* nextRequest() const;
    bool processRequest(const std::string& requestId);
    bool completeRequest(const std::string& requestId, RequestStatus outcome,
                         const std::string& details, ResourceModule& resources);
    bool cancelRequest(const std::string& requestId, ResourceModule& resources);
    bool removeTerminalRequest(const std::string& requestId);

    // Integration hooks: Task 1 checks active requests before deletion;
    // Task 3 updates assignments through this module instead of copying requests.
    bool hasActiveRequestForParcel(const std::string& parcelId) const;
    bool attachResource(const std::string& requestId, const std::string& resourceId);
    bool detachResource(const std::string& requestId);

private:
    ParcelModule& parcels_;
    RequestQueue requests_;
    unsigned long long nextRequestNumber_{1};
    unsigned long long nextSequence_{1};
};

} // namespace campus
