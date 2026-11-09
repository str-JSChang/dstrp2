#ifndef TASK1_HPP
#define TASK1_HPP

#include "models.hpp"
using namespace std;

namespace campus {
class ServiceModule;

// Task 1 - keep every parcel record, even after it leaves intake
class ParcelRecords {
public:
    ParcelRecords() = default;
    ~ParcelRecords();
    ParcelRecords(const ParcelRecords&) = delete;
    ParcelRecords& operator=(const ParcelRecords&) = delete;
    bool insert(const Parcel& parcel);
    Parcel* find(const string& id);
    const Parcel* find(const string& id) const;
    bool hasTrackingNumber(const string& tracking, const string& exceptId = "") const;
    bool remove(const string& id);
    void display() const;
private:
    struct Node {
        Parcel value;
        Node* next = nullptr;
    };
    Node* head = nullptr;
};

// only parcel IDs are needed in the waiting queue
class IntakeQueue {
public:
    IntakeQueue() = default;
    ~IntakeQueue();
    IntakeQueue(const IntakeQueue&) = delete;
    IntakeQueue& operator=(const IntakeQueue&) = delete;
    bool enqueue(const string& id);
    bool dequeue(string& id);
    bool peek(string& id) const;
    bool remove(const string& id);
    bool empty() const { return front == nullptr; }
    void display() const;
private:
    struct Node {
        string parcelId;
        Node* next = nullptr;
    };
    Node* front = nullptr;
    Node* rear = nullptr;
};

class ParcelModule {
public:
    bool registerParcel(Parcel parcel);
    void displayParcels() const;
    const Parcel* findParcel(const string& id) const;
    bool updateParcel(const string& id, Parcel replacement, const ServiceModule& services);
    bool removeParcel(const string& id, const ServiceModule& services);
    bool processNext(Route route, ServiceModule& services,
                     RequestPriority priority = RequestPriority::Normal);
    bool resumeParcel(const string& id, Route route, ServiceModule& services,
                      RequestPriority priority = RequestPriority::Normal);
    bool updateStatus(const string& id, ParcelStatus status, const ServiceModule& services);
    void displayWaiting() const;
private:
    friend class ServiceModule; // service lifecycle changes are coordinated here
    ParcelRecords records;
    IntakeQueue waiting;
    unsigned long long nextParcelNumber = 1;
};

} // namespace campus
#endif
