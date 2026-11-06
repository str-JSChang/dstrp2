#pragma once

#include <string>

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
    std::string id;
    std::string recipientName;
    std::string recipientId;
    std::string recipientContact;
    std::string deliveryCompany;
    std::string trackingNumber;
    std::string destination;
    std::string parcelType;
    std::string arrivalTime; // Planned format: YYYY-MM-DD HH:MM:SS (local time).
    ParcelStatus status{ParcelStatus::Received};
};

struct ServiceRequest {
    std::string id;
    std::string parcelId; // Reference to Task 1's authoritative record.
    ServiceType type{ServiceType::Collection};
    RequestPriority priority{RequestPriority::Normal};
    RequestStatus status{RequestStatus::Pending};
    std::string recipientId;
    std::string serviceDetails;
    std::string createdAt;
    unsigned long long sequence{0}; // Increasing creation sequence breaks priority ties.
    std::string resourceId; // Empty until Task 3 allocates a resource.
    std::string outcomeDetails;
};

struct Resource {
    std::string id;
    std::string name;
    ResourceType type{ResourceType::CollectionCounter};
    ResourceStatus status{ResourceStatus::Available};
    std::string assignedRequestId; // Empty when no active assignment exists.
};

} // namespace campus
