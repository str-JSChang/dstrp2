#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include <iostream>
#include <sstream>
#include <string>

namespace {
using namespace campus;

std::string readText(const char* prompt) {
    std::cout << prompt;
    std::string text;
    std::getline(std::cin, text);
    return text;
}

// EOF exits menus cleanly; malformed or out-of-range input is retried.
int choice(const char* prompt, int low, int high) {
    for (;;) {
        const std::string line = readText(prompt);
        if (!std::cin) return 0;
        std::istringstream input(line);
        int value = 0;
        char extra = '\0';
        if ((input >> value) && !(input >> extra) && value >= low && value <= high)
            return value;
        std::cout << "Enter a number from " << low << " to " << high << ".\n";
    }
}

Parcel readParcelDetails() {
    Parcel parcel;
    parcel.recipientName = readText("Recipient name: ");
    parcel.recipientId = readText("Recipient student/staff ID: ");
    parcel.recipientContact = readText("Recipient contact: ");
    parcel.deliveryCompany = readText("Delivery company: ");
    parcel.trackingNumber = readText("Tracking number: ");
    parcel.destination = readText("Campus destination: ");
    parcel.parcelType = readText("Parcel type: ");
    return parcel;
}

void parcelMenu(ParcelModule& parcels, ServiceModule& services) {
    while (std::cin) {
        const int action = choice(
            "\nTASK 1 - PARCEL INTAKE\n"
            "1. Register parcel\n2. Display parcels\n3. Search parcel\n"
            "4. Process next waiting parcel\n5. Update parcel details\n"
            "6. Remove cancelled parcel\n7. Display waiting queue\n"
            "8. Report missing / place on hold\n0. Back\nChoice: ", 0, 8);
        if (action == 0) return;
        switch (action) {
        case 1: {
            const Parcel parcel = readParcelDetails();
            if (std::cin) parcels.registerParcel(parcel);
            break;
        }
        case 2: parcels.displayParcels(); break;
        case 3: {
            const auto id = readText("Parcel ID: ");
            if (std::cin) {
                if (const Parcel* parcel = parcels.findParcel(id))
                    std::cout << "Parcel: " << parcel->id << " | " << parcel->recipientName << '\n';
            }
            break;
        }
        case 4: {
            const int route = choice("1. Collection\n2. Campus delivery\n3. Special handling\n"
                                     "4. Return to sender\n5. Investigation hold\n0. Cancel\nRoute: ", 0, 5);
            if (route) parcels.processNext(static_cast<Route>(route - 1), services);
            break;
        }
        case 5: {
            const auto id = readText("Parcel ID to update: ");
            Parcel replacement = readParcelDetails();
            replacement.id = id;
            if (std::cin) parcels.updateParcel(id, replacement);
            break;
        }
        case 6: {
            const auto id = readText("Cancelled parcel ID to remove: ");
            if (std::cin) parcels.removeParcel(id, services);
            break;
        }
        case 7: parcels.displayWaiting(); break;
        case 8: {
            const auto id = readText("Parcel ID: ");
            const int state = choice("1. Missing\n2. On hold\n0. Cancel\nStatus: ", 0, 2);
            if (state) parcels.updateStatus(id, state == 1 ? ParcelStatus::Missing : ParcelStatus::OnHold);
            break;
        }
        }
    }
}

void serviceMenu(ServiceModule& services, ResourceModule& resources) {
    while (std::cin) {
        const int action = choice(
            "\nTASK 2 - SERVICE REQUESTS\n1. Create request\n2. Display active requests\n"
            "3. View next request\n4. Process request\n5. Complete / return request\n"
            "6. Cancel request\n7. Remove terminal request\n8. Search request\n0. Back\nChoice: ", 0, 8);
        if (action == 0) return;
        switch (action) {
        case 1: {
            ServiceRequest request;
            request.parcelId = readText("Parcel ID: ");
            request.recipientId = readText("Recipient ID: ");
            request.serviceDetails = readText("Service details: ");
            const int type = choice("1. Collection\n2. Campus delivery\n3. Special handling\n"
                                    "4. Redelivery\n5. Return to sender\n0. Cancel\nService: ", 0, 5);
            if (!type) break;
            request.type = static_cast<ServiceType>(type - 1);
            const int priority = choice("1. Urgent\n2. Normal\n0. Cancel\nPriority: ", 0, 2);
            if (!priority) break;
            request.priority = priority == 1 ? RequestPriority::Urgent : RequestPriority::Normal;
            services.createRequest(request);
            break;
        }
        case 2: services.displayActiveRequests(); break;
        case 3:
            if (const auto* request = services.nextRequest())
                std::cout << "Next request: " << request->id << '\n';
            break;
        case 4: {
            const auto id = readText("Request ID: ");
            if (std::cin) services.processRequest(id);
            break;
        }
        case 5: {
            const auto id = readText("Request ID: ");
            const int outcome = choice("1. Completed\n2. Returned\n0. Cancel\nOutcome: ", 0, 2);
            if (!outcome) break;
            const auto details = readText("Completion / return details: ");
            if (std::cin) services.completeRequest(id, outcome == 1 ? RequestStatus::Completed : RequestStatus::Returned,
                                                 details, resources);
            break;
        }
        case 6: {
            const auto id = readText("Request ID to cancel: ");
            if (std::cin) services.cancelRequest(id, resources);
            break;
        }
        case 7: {
            const auto id = readText("Terminal request ID to remove: ");
            if (std::cin) services.removeTerminalRequest(id);
            break;
        }
        case 8: {
            const auto id = readText("Request ID: ");
            if (std::cin) {
                if (const auto* request = services.findRequest(id))
                    std::cout << "Request: " << request->id << " | Parcel: " << request->parcelId << '\n';
            }
            break;
        }
        }
    }
}

void resourceMenu(ResourceModule& resources) {
    while (std::cin) {
        const int action = choice(
            "\nTASK 3 - RESOURCES\n1. Register resource\n2. Display availability\n"
            "3. Assign request\n4. Release resource\n5. Update resource status\n"
            "6. Update resource name\n0. Back\nChoice: ", 0, 6);
        if (action == 0) return;
        switch (action) {
        case 1: {
            Resource resource;
            resource.id = readText("Unique resource ID: ");
            resource.name = readText("Counter / personnel name: ");
            const int type = choice("1. Collection counter\n2. Delivery personnel\n0. Cancel\nType: ", 0, 2);
            if (!type) break;
            resource.type = static_cast<ResourceType>(type - 1);
            resources.registerResource(resource);
            break;
        }
        case 2: resources.displayAvailability(); break;
        case 3: {
            const auto id = readText("Request ID: ");
            const int type = choice("1. Collection counter\n2. Delivery personnel\n0. Cancel\nRequired type: ", 0, 2);
            if (type) resources.assignRequest(id, static_cast<ResourceType>(type - 1));
            break;
        }
        case 4: {
            const auto id = readText("Resource ID: ");
            if (std::cin) resources.releaseResource(id);
            break;
        }
        case 5: {
            const auto id = readText("Resource ID: ");
            const int status = choice("1. Available\n2. Occupied\n3. Unavailable\n0. Cancel\nStatus: ", 0, 3);
            if (status) resources.updateStatus(id, static_cast<ResourceStatus>(status - 1));
            break;
        }
        case 6: {
            const auto id = readText("Resource ID: ");
            const auto name = readText("New name: ");
            if (std::cin) resources.updateResourceDetails(id, name);
            break;
        }
        }
    }
}
} // namespace

int main() {
    campus::ParcelModule parcels;
    campus::ServiceModule services(parcels);
    campus::ResourceModule resources(services);
    std::cout << "SMART CAMPUS PARCEL SYSTEM - STARTER SKELETON\n"
                 "Menus work; data structures and business operations are TODOs.\n";
    while (std::cin) {
        const int action = choice("\n1. Task 1 - Parcel intake\n2. Task 2 - Services\n"
                                  "3. Task 3 - Resources\n0. Exit\nChoice: ", 0, 3);
        if (action == 0) break;
        if (action == 1) parcelMenu(parcels, services);
        if (action == 2) serviceMenu(services, resources);
        if (action == 3) resourceMenu(resources);
    }
    std::cout << "Goodbye.\n";
}
