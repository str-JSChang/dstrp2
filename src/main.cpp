#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
using namespace std;

namespace {
using namespace campus;

string readText(const char* prompt) {
    if (!cin) {
        return "";
    }
    cout << prompt;
    string text;
    getline(cin, text);
    return trim(text);
}

// EOF exits menus cleanly; malformed or out-of-range input is retried.
int choice(const char* prompt, int low, int high) {
    while (true) {
        const string line = readText(prompt);
        if (!cin) {
            return 0;
        }
        istringstream input(line);
        int value = 0;
        char extra = '\0';
        // check the number, extra characters and range separately
        if (!(input >> value)) {
            cout << "Enter a number from " << low << " to " << high << ".\n";
            continue;
        }
        if (input >> extra) {
            cout << "Enter one number without extra characters.\n";
            continue;
        }
        if (value < low || value > high) {
            cout << "Enter a number from " << low << " to " << high << ".\n";
            continue;
        }
        return value;
    }
}

// return false when staff cancel or input ends
bool readPriority(RequestPriority& priority) {
    int selection = choice("1. Urgent\n2. Normal\n0. Cancel\nPriority: ", 0, 2);
    if (selection == 0) {
        return false;
    }
    if (selection == 1) {
        priority = RequestPriority::Urgent;
    }
    else {
        priority = RequestPriority::Normal;
    }
    return true;
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

void showResult(bool success) {
    if (success) {
        cout << "Operation successful.\n";
    }
    else {
        cout << "Operation failed; see the reason above.\n";
    }
}

void parcelMenu(ParcelModule& parcels, ServiceModule& services) {
    while (cin) {
        const int action = choice(
            "\nTASK 1 - PARCEL INTAKE\n"
            "1. Register parcel\n2. Display parcels\n3. Search parcel\n"
            "4. Process next waiting parcel\n5. Update parcel details\n"
            "6. Remove cancelled parcel\n7. Display waiting queue\n"
            "8. Report missing / place on hold\n9. Resume held/recovered parcel\n0. Back\nChoice: ", 0, 9);
        if (action == 0) {
            return;
        }
        switch (action) {
        case 1: {
            const Parcel parcel = readParcelDetails();
            if (cin) {
                showResult(parcels.registerParcel(parcel));
            }
            break;
        }
        case 2:
            parcels.displayParcels();
            break;
        case 3: {
            const string id = readText("Parcel ID: ");
            if (cin) {
                const Parcel* parcel = parcels.findParcel(id);
                if (parcel != nullptr) {
                    printParcel(*parcel);
                }
            }
            break;
        }
        case 4: {
            const int route = choice("1. Collection\n2. Campus delivery\n3. Special handling\n"
                                     "4. Return to sender\n5. Investigation hold\n0. Cancel\nRoute: ", 0, 5);
            if (route == 0) {
                break;
            }
            RequestPriority priority = RequestPriority::Normal;
            if (route != 5) {
                if (!readPriority(priority)) {
                    break;
                }
            }
            Route selectedRoute = static_cast<Route>(route - 1);
            bool success = parcels.processNext(selectedRoute, services, priority);
            showResult(success);
            break;
        }
        case 5: {
            const string id = readText("Parcel ID to update: ");
            Parcel replacement = readParcelDetails();
            replacement.id = id;
            if (cin) {
                showResult(parcels.updateParcel(id, replacement, services));
            }
            break;
        }
        case 6: {
            const string id = readText("Cancelled parcel ID to remove: ");
            if (cin) {
                showResult(parcels.removeParcel(id, services));
            }
            break;
        }
        case 7:
            parcels.displayWaiting();
            break;
        case 8: {
            const string id = readText("Parcel ID: ");
            const int state = choice("1. Missing\n2. On hold / recovered\n3. Cancel parcel\n0. Back\nStatus: ", 0, 3);
            if (state != 0) {
                ParcelStatus status;
                if (state == 1) {
                    status = ParcelStatus::Missing;
                }
                else if (state == 2) {
                    status = ParcelStatus::OnHold;
                }
                else {
                    status = ParcelStatus::Cancelled;
                }
                showResult(parcels.updateStatus(id, status, services));
                cout << "For an active request, use Task 2 interruption/cancellation first.\n";
            }
            break;
        }
        case 9: {
            const string id = readText("Parcel ID to resume: ");
            int route = choice("1. Collection\n2. Campus delivery\n3. Special handling\n4. Return to sender\n0. Cancel\nRoute: ", 0, 4);
            if (route == 0) {
                break;
            }
            RequestPriority priority;
            if (!readPriority(priority)) {
                break;
            }
            Route selectedRoute = static_cast<Route>(route - 1);
            bool success = parcels.resumeParcel(id, selectedRoute, services, priority);
            showResult(success);
            break;
        }
        }
    }
}

void serviceMenu(ServiceModule& services, ResourceModule& resources) {
    while (cin) {
        const int action = choice(
            "\nTASK 2 - SERVICE REQUESTS\n1. Create request\n2. Display active requests\n"
            "3. View next request\n4. Process request\n5. Complete / return request\n"
            "6. Cancel request\n7. Remove terminal request\n8. Search request\n"
            "9. Interrupt request: missing / hold\n0. Back\nChoice: ", 0, 9);
        if (action == 0) {
            return;
        }
        switch (action) {
        case 1: {
            ServiceRequest request;
            request.parcelId = readText("Parcel ID: ");
            request.recipientId = readText("Recipient ID: ");
            request.serviceDetails = readText("Service details: ");
            const int type = choice("1. Collection\n2. Campus delivery\n3. Special handling\n"
                                    "4. Redelivery\n5. Return to sender\n0. Cancel\nService: ", 0, 5);
            if (type == 0) {
                break;
            }
            request.type = static_cast<ServiceType>(type - 1);
            if (!readPriority(request.priority)) {
                break;
            }
            showResult(services.createRequest(request));
            break;
        }
        case 2:
            services.displayActiveRequests();
            break;
        case 3: {
            const ServiceRequest* request = services.nextRequest();
            if (request != nullptr) {
                cout << "Next request: " << request->id << '\n';
            }
            break;
        }
        case 4: {
            const string id = readText("Request ID: ");
            if (cin) {
                showResult(services.processRequest(id));
            }
            break;
        }
        case 5: {
            const string id = readText("Request ID: ");
            const int outcome = choice("1. Completed\n2. Returned\n0. Cancel\nOutcome: ", 0, 2);
            if (outcome == 0) {
                break;
            }
            const string details = readText("Completion / return details: ");
            const string recipientId = readText("Verify recipient ID: ");
            if (cin) {
                RequestStatus finalStatus;
                if (outcome == 1) {
                    finalStatus = RequestStatus::Completed;
                }
                else {
                    finalStatus = RequestStatus::Returned;
                }
                bool success = services.completeRequest(id, finalStatus, details, recipientId, resources);
                showResult(success);
            }
            break;
        }
        case 6: {
            const string id = readText("Request ID to cancel: ");
            if (cin) {
                showResult(services.cancelRequest(id, resources));
            }
            break;
        }
        case 7: {
            const string id = readText("Terminal request ID to remove: ");
            if (cin) {
                showResult(services.removeTerminalRequest(id));
            }
            break;
        }
        case 8: {
            const string id = readText("Request ID: ");
            if (cin) {
                const ServiceRequest* request = services.findRequest(id);
                if (request != nullptr) {
                    printRequest(*request);
                }
            }
            break;
        }
        case 9: {
            const string id = readText("Request ID to interrupt: ");
            int status = choice("1. Missing\n2. Investigation hold\n0. Back\nParcel status: ", 0, 2);
            if (status != 0) {
                ParcelStatus parcelStatus;
                if (status == 1) {
                    parcelStatus = ParcelStatus::Missing;
                }
                else {
                    parcelStatus = ParcelStatus::OnHold;
                }
                bool success = services.interruptRequest(id, parcelStatus, resources);
                showResult(success);
            }
            break;
        }
        }
    }
}

void resourceMenu(ResourceModule& resources) {
    while (cin) {
        const int action = choice(
            "\nTASK 3 - RESOURCES\n1. Register resource\n2. Display availability\n"
            "3. Assign request\n4. Release resource\n5. Update resource status\n"
            "6. Update resource name\n0. Back\nChoice: ", 0, 6);
        if (action == 0) {
            return;
        }
        switch (action) {
        case 1: {
            Resource resource;
            resource.id = readText("Unique resource ID: ");
            resource.name = readText("Counter / personnel name: ");
            const int type = choice("1. Collection counter\n2. Delivery personnel\n0. Cancel\nType: ", 0, 2);
            if (type == 0) {
                break;
            }
            resource.type = static_cast<ResourceType>(type - 1);
            showResult(resources.registerResource(resource));
            break;
        }
        case 2:
            resources.displayAvailability();
            break;
        case 3: {
            const string id = readText("Request ID: ");
            const int type = choice("1. Collection counter\n2. Delivery personnel\n0. Cancel\nRequired type: ", 0, 2);
            if (type != 0) {
                showResult(resources.assignRequest(id, static_cast<ResourceType>(type - 1)));
            }
            break;
        }
        case 4: {
            const string id = readText("Resource ID: ");
            if (cin) {
                showResult(resources.releaseResource(id));
            }
            break;
        }
        case 5: {
            const string id = readText("Resource ID: ");
            const int status = choice("1. Available\n2. Occupied\n3. Unavailable\n0. Cancel\nStatus: ", 0, 3);
            if (status != 0) {
                showResult(resources.updateStatus(id, static_cast<ResourceStatus>(status - 1)));
            }
            break;
        }
        case 6: {
            const string id = readText("Resource ID: ");
            const string name = readText("New name: ");
            if (cin) {
                showResult(resources.updateResourceDetails(id, name));
            }
            break;
        }
        }
    }
}
} // namespace

int runSystem() {
    campus::ParcelModule parcels;
    campus::ServiceModule services(parcels);
    campus::ResourceModule resources(services);
    cout << "SMART CAMPUS PARCEL COLLECTION AND DELIVERY SYSTEM\n"
                 "Three-task integrated prototype (in-memory data).\n";
    while (cin) {
        const int action = choice("\n1. Task 1 - Parcel intake\n2. Task 2 - Services\n"
                                  "3. Task 3 - Resources\n0. Exit\nChoice: ", 0, 3);
        if (action == 0) {
            break;
        }
        if (action == 1) {
            parcelMenu(parcels, services);
        }
        if (action == 2) {
            serviceMenu(services, resources);
        }
        if (action == 3) {
            resourceMenu(resources);
        }
    }
    cout << "Goodbye.\n";
    return 0;
}

int main() {
    try {
        return runSystem();
    }
    catch (const exception& error) {
        cerr << "System stopped: " << error.what() << '\n';
        return 1;
    }
}
