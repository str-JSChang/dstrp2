#pragma once

#include "models.hpp"
#include <cstddef>

namespace campus {

class ServiceModule;

// Member 1: authoritative parcel storage. All core algorithms are TODOs.
class ParcelRecords {
public:
    ParcelRecords() = default;
    ~ParcelRecords();
    ParcelRecords(const ParcelRecords&) = delete;
    ParcelRecords& operator=(const ParcelRecords&) = delete;

    bool insert(const Parcel& parcel);
    Parcel* find(const std::string& parcelId);
    const Parcel* find(const std::string& parcelId) const;
    bool remove(const std::string& parcelId);
    void display() const;

private:
    struct Node { Parcel value; Node* next{nullptr}; };
    Node* head_{nullptr};
};

// Stores IDs only; dequeuing must not delete the corresponding parcel record.
class IntakeQueue {
public:
    IntakeQueue() = default;
    ~IntakeQueue();
    IntakeQueue(const IntakeQueue&) = delete;
    IntakeQueue& operator=(const IntakeQueue&) = delete;

    bool enqueue(const std::string& parcelId);
    bool dequeue(std::string& parcelId);
    bool peek(std::string& parcelId) const;
    bool empty() const noexcept { return front_ == nullptr; }
    void display() const;

private:
    struct Node { std::string parcelId; Node* next{nullptr}; };
    Node* front_{nullptr};
    Node* rear_{nullptr};
};

class ParcelModule {
public:
    bool registerParcel(Parcel parcel); // Generate unique ID and arrival time here.
    void displayParcels() const;
    const Parcel* findParcel(const std::string& parcelId) const;
    bool updateParcel(const std::string& parcelId, const Parcel& replacement);
    bool removeParcel(const std::string& parcelId, const ServiceModule& services);
    bool processNext(Route route, ServiceModule& services);
    void displayWaiting() const;

    // Integration hook: validate transitions before changing shared parcel state.
    bool updateStatus(const std::string& parcelId, ParcelStatus status);

private:
    ParcelRecords records_;
    IntakeQueue waiting_;
    unsigned long long nextParcelNumber_{1};
};

} // namespace campus
