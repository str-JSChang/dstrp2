#ifndef MODELS_HPP
#define MODELS_HPP

#include <string>
#include <utility>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

namespace campus {

enum class ParcelStatus {
    Received, AwaitingCollection, AwaitingDelivery, SpecialHandling,
    ReturnPending, OnHold, Missing, Collected, Delivered, Returned, Cancelled
};
enum class Route { Collection, CampusDelivery, SpecialHandling, ReturnToSender, InvestigationHold };
enum class ServiceType { Collection, CampusDelivery, SpecialHandling, Redelivery, ReturnToSender };
enum class RequestPriority { Urgent, Normal };
enum class RequestStatus { Pending, Assigned, InProgress, Completed, Cancelled, Returned };
enum class ResourceType { CollectionCounter, DeliveryPersonnel };
enum class ResourceStatus { Available, Occupied, Unavailable };

struct Parcel {
    string id;
    string recipientName;
    string recipientId;
    string recipientContact;
    string deliveryCompany;
    string trackingNumber;
    string destination;
    string parcelType;
    string arrivalTime;
    ParcelStatus status = ParcelStatus::Received;
};

struct ServiceRequest {
    string id;
    string parcelId;
    ServiceType type = ServiceType::Collection;
    RequestPriority priority = RequestPriority::Normal;
    RequestStatus status = RequestStatus::Pending;
    string recipientId;
    string serviceDetails;
    string createdAt;
    unsigned long long sequence = 0;
    string resourceId;
    string outcomeDetails;
};

struct Resource {
    string id;
    string name;
    ResourceType type = ResourceType::CollectionCounter;
    ResourceStatus status = ResourceStatus::Available;
    string assignedRequestId;
};

// remove outside whitespace, while leaving spaces inside names alone
inline string trim(const string& text) {
    size_t first = text.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = text.find_last_not_of(" \t\r\n");
    return text.substr(first, last - first + 1);
}

inline string currentTimestamp() {
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm local = {};
#ifdef _WIN32
    localtime_s(&local, &now);
#else
    localtime_r(&now, &local);
#endif
    ostringstream stamp;
    stamp << put_time(&local, "%Y-%m-%d %H:%M:%S");
    return stamp.str();
}

inline bool isTerminal(ParcelStatus status) {
    return status == ParcelStatus::Collected || status == ParcelStatus::Delivered
        || status == ParcelStatus::Returned || status == ParcelStatus::Cancelled;
}

inline bool isActive(RequestStatus status) {
    return status == RequestStatus::Pending || status == RequestStatus::Assigned
        || status == RequestStatus::InProgress;
}

inline bool validService(ServiceType type) {
    return type >= ServiceType::Collection && type <= ServiceType::ReturnToSender;
}

// the request type determines which parcel status it must have
inline ParcelStatus serviceStatus(ServiceType type) {
    switch (type) {
    case ServiceType::Collection: return ParcelStatus::AwaitingCollection;
    case ServiceType::CampusDelivery:
    case ServiceType::Redelivery: return ParcelStatus::AwaitingDelivery;
    case ServiceType::SpecialHandling: return ParcelStatus::SpecialHandling;
    case ServiceType::ReturnToSender: return ParcelStatus::ReturnPending;
    }
    return ParcelStatus::OnHold;
}

inline ResourceType serviceResource(ServiceType type) {
    if (type == ServiceType::Collection) return ResourceType::CollectionCounter;
    return ResourceType::DeliveryPersonnel;
}

inline const char* toString(ParcelStatus status) {
    switch (status) {
    case ParcelStatus::Received: return "Received";
    case ParcelStatus::AwaitingCollection: return "Awaiting collection";
    case ParcelStatus::AwaitingDelivery: return "Awaiting delivery";
    case ParcelStatus::SpecialHandling: return "Special handling";
    case ParcelStatus::ReturnPending: return "Return pending";
    case ParcelStatus::OnHold: return "On hold";
    case ParcelStatus::Missing: return "Missing";
    case ParcelStatus::Collected: return "Collected";
    case ParcelStatus::Delivered: return "Delivered";
    case ParcelStatus::Returned: return "Returned";
    case ParcelStatus::Cancelled: return "Cancelled";
    }
    return "Unknown";
}

inline const char* toString(RequestStatus status) {
    switch (status) {
    case RequestStatus::Pending: return "Pending";
    case RequestStatus::Assigned: return "Assigned";
    case RequestStatus::InProgress: return "In progress";
    case RequestStatus::Completed: return "Completed";
    case RequestStatus::Cancelled: return "Cancelled";
    case RequestStatus::Returned: return "Returned";
    }
    return "Unknown";
}

inline const char* toString(ServiceType type) {
    switch (type) {
    case ServiceType::Collection: return "Collection";
    case ServiceType::CampusDelivery: return "Campus delivery";
    case ServiceType::SpecialHandling: return "Special handling";
    case ServiceType::Redelivery: return "Redelivery";
    case ServiceType::ReturnToSender: return "Return to sender";
    }
    return "Unknown";
}

inline const char* toString(ResourceStatus status) {
    switch (status) {
    case ResourceStatus::Available: return "Available";
    case ResourceStatus::Occupied: return "Occupied";
    case ResourceStatus::Unavailable: return "Unavailable";
    }
    return "Unknown";
}

inline void printParcel(const Parcel& parcel) {
    cout << parcel.id << " | " << parcel.recipientName << " | recipient " << parcel.recipientId
         << " | contact " << parcel.recipientContact << " | carrier " << parcel.deliveryCompany
         << " | tracking " << parcel.trackingNumber << " | destination " << parcel.destination
         << " | type " << parcel.parcelType << " | status " << toString(parcel.status)
         << " | arrived " << parcel.arrivalTime << '\n';
}

inline void printRequest(const ServiceRequest& request) {
    cout << request.id << " | parcel " << request.parcelId << " | " << toString(request.type)
         << " | " << (request.priority == RequestPriority::Urgent ? "Urgent" : "Normal")
         << " | status " << toString(request.status) << " | recipient " << request.recipientId
         << " | details " << request.serviceDetails << " | created " << request.createdAt
         << " | resource " << (request.resourceId.empty() ? "-" : request.resourceId)
         << " | outcome " << (request.outcomeDetails.empty() ? "-" : request.outcomeDetails) << '\n';
}

} // namespace campus
#endif
