#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include <stdexcept>
#include <sstream>
using namespace std;
using namespace campus;

int checks = 0;

void check(bool condition, const string& message) {
    checks++;
    if (!condition) throw runtime_error(message);
}

Parcel sampleParcel(const string& tracking = "TRACK1") {
    Parcel parcel;
    parcel.recipientName = "Alice";
    parcel.recipientId = "TP001";
    parcel.recipientContact = "0123456789";
    parcel.deliveryCompany = "Campus Courier";
    parcel.trackingNumber = tracking;
    parcel.destination = "Block A";
    parcel.parcelType = "Box";
    return parcel;
}

struct Fixture {
    ParcelModule parcels;
    ServiceModule services{parcels};
    ResourceModule resources{services};

    void registerParcel(const string& tracking = "TRACK1") {
        check(parcels.registerParcel(sampleParcel(tracking)), "registration failed");
    }

    void registerResource(const string& id, ResourceType type) {
        Resource resource;
        resource.id = id;
        resource.name = id + " name";
        resource.type = type;
        check(resources.registerResource(resource), "resource registration failed");
    }

    void create(ServiceType type, const string& parcelId = "P1",
                RequestPriority priority = RequestPriority::Normal) {
        ServiceRequest request;
        request.parcelId = parcelId;
        request.recipientId = "TP001";
        request.serviceDetails = "Staff service request";
        request.type = type;
        request.priority = priority;
        check(services.createRequest(request), "request creation failed");
    }

    void assignAndProcess(const string& id, ResourceType type) {
        check(resources.assignRequest(id, type), "assignment failed");
        check(services.processRequest(id), "processing failed");
    }
};

void testLinkedStructures() {
    ParcelRecords records;
    check(records.find("X") == nullptr && !records.remove("X"), "empty list lookup/remove");
    Parcel parcel = sampleParcel();
    parcel.id = "A";
    check(records.insert(parcel), "insert A");
    check(!records.insert(parcel), "duplicate record ID");
    parcel.id = "B";
    check(records.insert(parcel), "insert B");
    parcel.id = "C";
    check(records.insert(parcel), "insert C");
    check(records.remove("B") && records.find("A") && records.find("C"), "middle removal");
    check(records.remove("C") && records.remove("A") && !records.remove("A"), "head and only removal");
    check(records.insert(parcel) && records.remove("C"), "reuse empty list");

    IntakeQueue queue;
    string id = "unchanged";
    check(queue.empty() && !queue.dequeue(id) && !queue.peek(id), "empty intake operations");
    check(id == "unchanged", "empty operation changed output");
    check(!queue.enqueue(" "), "blank queue ID accepted");
    queue.enqueue("A"); queue.enqueue("B"); queue.enqueue("C");
    check(queue.peek(id) && id == "A", "FIFO head");
    check(queue.remove("B") && queue.remove("C"), "queue middle and tail removal");
    queue.enqueue("D");
    check(queue.dequeue(id) && id == "A", "FIFO first");
    check(queue.dequeue(id) && id == "D" && queue.empty(), "rear repaired after removal");
    queue.enqueue("E");
    check(queue.remove("E") && queue.empty(), "only queue node removal");
    queue.enqueue("F");
    check(queue.dequeue(id) && id == "F", "queue reuse after empty");

    RequestQueue requests;
    check(!requests.nextPending() && !requests.remove("X"), "empty requests");
    ServiceRequest request;
    request.id = "N1"; request.sequence = 1;
    check(requests.insert(request), "normal insertion");
    request.id = "U1"; request.priority = RequestPriority::Urgent; request.sequence = 2;
    check(requests.insert(request), "urgent insertion");
    request.id = "U2"; request.sequence = 3;
    check(requests.insert(request) && !requests.insert(request), "duplicate request ID");
    check(requests.nextPending()->id == "U1", "urgent first with FIFO ties");
    requests.find("U1")->status = RequestStatus::Assigned;
    check(requests.nextPending()->id == "U2", "skip assigned request");
    requests.find("U2")->status = RequestStatus::Completed;
    check(requests.nextPending()->id == "N1", "skip terminal request");
    check(requests.remove("U2") && requests.remove("U1") && requests.remove("N1"), "request deletion boundaries");
    check(!requests.nextPending(), "request queue empty after removal");

    ResourceRing ring;
    check(!ring.find("X") && !ring.nextAvailable(ResourceType::CollectionCounter), "empty resource ring");
    Resource resource;
    resource.id = "A"; resource.name = "A";
    check(ring.insert(resource) && !ring.insert(resource), "ring duplicate ID");
    check(ring.nextAvailable(resource.type)->id == "A", "single-node ring");
    resource.id = "B"; check(ring.insert(resource), "second ring node");
    check(ring.nextAvailable(resource.type)->id == "A", "ring cursor after insertion");
    check(ring.nextAvailable(resource.type)->id == "B", "round-robin second");
    check(ring.nextAvailable(resource.type)->id == "A", "round-robin wrap");
    ring.find("A")->status = ResourceStatus::Unavailable;
    ring.find("B")->status = ResourceStatus::Occupied;
    check(!ring.nextAvailable(resource.type), "all resources unavailable stops after one cycle");
    check(!ring.nextAvailable(ResourceType::DeliveryPersonnel), "wrong-type ring scan");
    ring.find("A")->status = ResourceStatus::Available;
    ring.find("B")->status = ResourceStatus::Available;
    resource.id = "D"; resource.type = ResourceType::DeliveryPersonnel;
    check(ring.insert(resource), "insert mixed resource type");
    check(ring.nextAvailable(ResourceType::CollectionCounter)->id == "B", "counter cursor preserved");
    check(ring.nextAvailable(ResourceType::DeliveryPersonnel)->id == "D", "select delivery resource");
    check(ring.nextAvailable(ResourceType::CollectionCounter)->id == "A", "separate cursors prevent mixed-type starvation");

}

void testParcelValidation() {
    Fixture f;
    Parcel parcel = sampleParcel();
    parcel.recipientName = " \t ";
    check(!f.parcels.registerParcel(parcel), "whitespace recipient accepted");
    f.registerParcel();
    check(!f.parcels.registerParcel(sampleParcel()), "duplicate tracking accepted");
    f.registerParcel("TRACK2");
    check(f.parcels.findParcel("P2") != nullptr, "failed registration consumed ID");
    parcel = sampleParcel("TRACK2");
    check(!f.parcels.updateParcel("P1", parcel, f.services), "duplicate tracking edit accepted");
    parcel = sampleParcel("NEW"); parcel.recipientName = "  Bob  ";
    check(f.parcels.updateParcel("P1", parcel, f.services), "valid edit failed");
    check(f.parcels.findParcel("P1")->recipientName == "Bob", "trimmed name");
    check(f.parcels.findParcel("P1")->status == ParcelStatus::Received, "edit changed status");
    check(!f.parcels.removeParcel("P1", f.services), "live parcel removed");
    check(f.parcels.updateStatus("P1", ParcelStatus::Cancelled, f.services), "cancel unprocessed parcel");
    check(f.parcels.removeParcel("P1", f.services), "cancelled parcel removal");
    check(f.parcels.processNext(Route::Collection, f.services), "FIFO after cancelled removal");
    check(f.services.findRequest("R1")->parcelId == "P2", "processed wrong FIFO parcel");
    check(!f.parcels.processNext(Route::Collection, f.services), "empty intake accepted");
    check(!f.parcels.findParcel("UNKNOWN"), "unknown parcel found");
}

void testEveryServiceLifecycle() {
    for (int value = 0; value <= 4; value++) {
        Fixture f;
        ServiceType type = static_cast<ServiceType>(value);
        ResourceType resourceType = serviceResource(type);
        f.registerParcel();
        f.registerResource("RES", resourceType);
        f.create(type);
        check(f.parcels.findParcel("P1")->status == serviceStatus(type), "direct request did not synchronize parcel");
        check(!f.parcels.processNext(Route::Collection, f.services), "direct request left parcel in intake");
        check(!f.services.completeRequest("R1", RequestStatus::Completed, "Done", "TP001", f.resources), "unassigned completion");
        check(!f.services.processRequest("R1"), "unassigned processing");
        f.assignAndProcess("R1", resourceType);
        check(!f.services.processRequest("R1"), "repeated processing");
        check(f.services.completeRequest("R1", RequestStatus::Completed, "Done", "TP001", f.resources), "valid completion failed");
        ParcelStatus expected = type == ServiceType::Collection ? ParcelStatus::Collected
            : type == ServiceType::SpecialHandling ? ParcelStatus::OnHold
            : type == ServiceType::ReturnToSender ? ParcelStatus::Returned : ParcelStatus::Delivered;
        check(f.parcels.findParcel("P1")->status == expected, "wrong final parcel status");
        RequestStatus expectedRequest = type == ServiceType::ReturnToSender ? RequestStatus::Returned : RequestStatus::Completed;
        check(f.services.findRequest("R1")->status == expectedRequest, "wrong final request status");
        check(f.resources.findResource("RES")->status == ResourceStatus::Available, "resource not freed");
        check(f.services.findRequest("R1")->resourceId.empty(), "request resource ID not cleared");
        check(f.resources.findResource("RES")->assignedRequestId.empty(), "resource request ID not cleared");
        if (type == ServiceType::CampusDelivery) {
            ServiceRequest retry;
            retry.parcelId = "P1"; retry.recipientId = "TP001";
            retry.type = ServiceType::Redelivery; retry.serviceDetails = "Retry delivered parcel";
            check(!f.services.createRequest(retry), "redelivery on delivered parcel accepted");
            check(f.parcels.findParcel("P1")->status == ParcelStatus::Delivered,
                  "rejected redelivery altered delivered parcel");
        }
        check(!f.services.cancelRequest("R1", f.resources), "terminal request cancelled again");
        check(!f.services.completeRequest("R1", RequestStatus::Completed, "Again", "TP001", f.resources), "repeated completion");
    }
}

void testFailedCompletionIsUnchanged() {
    Fixture f;
    f.registerParcel();
    f.registerResource("C1", ResourceType::CollectionCounter);
    f.create(ServiceType::Collection);
    check(f.resources.assignRequest("R1", ResourceType::CollectionCounter), "assignment");
    check(!f.services.completeRequest("R1", RequestStatus::Completed, "Done", "TP001", f.resources), "completion before processing");
    check(f.services.processRequest("R1"), "start processing");
    check(!f.services.completeRequest("R1", RequestStatus::Completed, "Done", "WRONG", f.resources), "incorrect collection identity");
    check(!f.services.completeRequest("R1", RequestStatus::Completed, " \t ", "TP001", f.resources), "blank outcome details");
    check(!f.services.completeRequest("R1", RequestStatus::Pending, "Done", "TP001", f.resources), "invalid outcome");
    check(!f.parcels.updateStatus("P1", ParcelStatus::Missing, f.services), "unsafe active parcel mutation");
    check(!f.parcels.updateParcel("P1", sampleParcel("NEW"), f.services), "active parcel edit");
    const ServiceRequest* request = f.services.findRequest("R1");
    check(request->status == RequestStatus::InProgress && request->resourceId == "C1", "failed completion altered request");
    check(f.resources.findResource("C1")->status == ResourceStatus::Occupied
        && f.resources.findResource("C1")->assignedRequestId == "R1", "failed completion freed resource");
    check(f.parcels.findParcel("P1")->status == ParcelStatus::AwaitingCollection, "failed completion changed parcel");
    check(f.services.completeRequest("R1", RequestStatus::Completed, "Verified", "TP001", f.resources), "retry completion");
    ServiceRequest redelivery;
    redelivery.parcelId = "P1"; redelivery.recipientId = "TP001";
    redelivery.type = ServiceType::Redelivery; redelivery.serviceDetails = "Try again";
    check(!f.services.createRequest(redelivery), "completed parcel reopened");
}

void testResourceInterruptionAndRecovery() {
    Fixture f;
    f.registerParcel();
    f.registerResource("D1", ResourceType::DeliveryPersonnel);
    f.create(ServiceType::CampusDelivery);
    check(!f.resources.assignRequest("R1", ResourceType::CollectionCounter), "wrong resource type assigned");
    f.assignAndProcess("R1", ResourceType::DeliveryPersonnel);
    check(!f.resources.assignRequest("R1", ResourceType::DeliveryPersonnel), "duplicate active assignment");
    check(f.resources.updateStatus("D1", ResourceStatus::Unavailable), "make occupied resource unavailable");
    check(f.services.findRequest("R1")->status == RequestStatus::Pending
        && f.services.findRequest("R1")->resourceId.empty(), "interruption did not detach request");
    check(!f.resources.assignRequest("R1", ResourceType::DeliveryPersonnel), "unavailable resource selected");
    check(!f.resources.releaseResource("D1"), "released unassigned resource");
    check(f.resources.updateStatus("D1", ResourceStatus::Available), "restore availability");
    f.assignAndProcess("R1", ResourceType::DeliveryPersonnel);
    check(f.services.interruptRequest("R1", ParcelStatus::Missing, f.resources), "report missing during processing");
    check(f.parcels.findParcel("P1")->status == ParcelStatus::Missing, "missing parcel status");
    check(f.services.findRequest("R1")->status == RequestStatus::Cancelled, "interrupted request still active");
    check(!f.services.completeRequest("R1", RequestStatus::Completed, "Done", "TP001", f.resources), "missing parcel completed");
    check(!f.parcels.resumeParcel("P1", Route::CampusDelivery, f.services), "missing parcel resumed without recovery");
    check(f.parcels.updateStatus("P1", ParcelStatus::OnHold, f.services), "mark recovered parcel");
    check(f.parcels.resumeParcel("P1", Route::CampusDelivery, f.services), "resume recovered parcel");
    f.assignAndProcess("R2", ResourceType::DeliveryPersonnel);
    check(f.services.completeRequest("R2", RequestStatus::Returned, "Unable to deliver", "TP001", f.resources), "return delivery");
    check(f.parcels.findParcel("P1")->status == ParcelStatus::Returned, "returned delivery status");
}

void testCancellationAndHold() {
    Fixture f;
    f.registerParcel();
    f.registerResource("C1", ResourceType::CollectionCounter);
    check(f.parcels.processNext(Route::InvestigationHold, f.services), "intake hold");
    check(f.parcels.resumeParcel("P1", Route::Collection, f.services), "resume held parcel");
    check(!f.parcels.removeParcel("P1", f.services), "removed active parcel");
    check(!f.services.removeTerminalRequest("R1"), "removed active request");
    check(f.services.cancelRequest("R1", f.resources), "cancel pending request");
    check(f.parcels.findParcel("P1")->status == ParcelStatus::Cancelled, "parcel not cancelled");
    check(f.services.removeTerminalRequest("R1"), "remove cancelled request");
    check(f.parcels.removeParcel("P1", f.services), "remove cancelled parcel");
    f.registerParcel("TRACK2");
    f.create(ServiceType::Collection, "P2");
    f.assignAndProcess("R2", ResourceType::CollectionCounter);
    check(f.services.cancelRequest("R2", f.resources), "cancel in-progress request");
    check(f.resources.findResource("C1")->status == ResourceStatus::Available, "cancel did not release resource");
    check(!f.services.cancelRequest("R2", f.resources), "cancel twice");
}

void testPriorityAndRoundRobin() {
    Fixture f;
    f.registerResource("C1", ResourceType::CollectionCounter);
    f.registerResource("C2", ResourceType::CollectionCounter);
    f.registerParcel("A"); f.registerParcel("B"); f.registerParcel("C");
    f.create(ServiceType::Collection, "P1");
    f.create(ServiceType::Collection, "P2", RequestPriority::Urgent);
    f.create(ServiceType::Collection, "P3", RequestPriority::Urgent);
    check(f.services.nextRequest()->id == "R2", "urgent FIFO recommendation");
    check(f.resources.assignRequest("R2", ResourceType::CollectionCounter), "allocate first counter");
    check(f.services.findRequest("R2")->resourceId == "C1", "first round-robin counter");
    check(f.services.nextRequest()->id == "R3", "next equal-priority request");
    check(f.resources.assignRequest("R3", ResourceType::CollectionCounter), "allocate second counter");
    check(f.services.findRequest("R3")->resourceId == "C2", "second round-robin counter");
    check(!f.resources.assignRequest("R1", ResourceType::CollectionCounter), "all occupied allocation");
    check(f.resources.releaseResource("C1"), "manual release");
    check(f.services.findRequest("R2")->status == RequestStatus::Pending, "manual release did not requeue");
    check(f.resources.assignRequest("R1", ResourceType::CollectionCounter), "allocate after release");
    check(f.services.findRequest("R1")->resourceId == "C1", "round-robin wrap allocation");
}

void testInvalidOperations() {
    Fixture f;
    check(!f.services.nextRequest(), "empty next request");
    check(!f.services.processRequest("X"), "unknown request processing");
    check(!f.services.cancelRequest("X", f.resources), "unknown cancellation");
    check(!f.resources.assignRequest("X", ResourceType::CollectionCounter), "unknown assignment");
    check(!f.resources.releaseResource("X"), "unknown resource release");
    check(!f.resources.updateStatus("X", ResourceStatus::Available), "unknown resource update");
    check(!f.parcels.processNext(static_cast<Route>(99), f.services), "invalid route");
    f.registerParcel();
    ServiceRequest request;
    request.parcelId = "P1"; request.recipientId = "WRONG"; request.serviceDetails = "Collect";
    check(!f.services.createRequest(request), "incorrect recipient request");
    request.recipientId = "TP001"; request.type = static_cast<ServiceType>(99);
    check(!f.services.createRequest(request), "invalid service enum");
    request.type = ServiceType::Collection; request.priority = static_cast<RequestPriority>(99);
    check(!f.services.createRequest(request), "invalid priority");
    request.priority = RequestPriority::Normal;
    check(f.services.createRequest(request), "valid request after invalid requests");
    check(!f.services.createRequest(request), "duplicate active request");
    check(f.services.findRequest("R1") != nullptr, "failed request consumed ID");
    f.registerResource("C1", ResourceType::CollectionCounter);
    check(!f.resources.updateStatus("C1", ResourceStatus::Occupied), "occupied without assignment");
    check(!f.resources.updateStatus("C1", static_cast<ResourceStatus>(99)), "invalid resource status");
    Resource duplicate;
    duplicate.id = "C1"; duplicate.name = "Duplicate";
    check(!f.resources.registerResource(duplicate), "duplicate resource ID");
    check(!f.resources.updateResourceDetails("C1", " \t"), "empty resource name");
}

int main() {
    ostringstream captured;
    streambuf* original = cout.rdbuf(captured.rdbuf());
    try {
        testLinkedStructures();
        testParcelValidation();
        testEveryServiceLifecycle();
        testFailedCompletionIsUnchanged();
        testResourceInterruptionAndRecovery();
        testCancellationAndHold();
        testPriorityAndRoundRobin();
        testInvalidOperations();
        // repeat object lifetimes to exercise deletion of nonempty linked structures
        for (int i = 0; i < 100; i++) {
            Fixture f;
            f.registerParcel();
            f.registerResource("C1", ResourceType::CollectionCounter);
            f.create(ServiceType::Collection);
        }
        cout.rdbuf(original);
        cout << "PASS: 8 suites, " << checks << " checks, including 100 lifetime cycles.\n";
        return 0;
    }
    catch (const exception& error) {
        cout.rdbuf(original);
        cerr << "FAIL after " << checks << " checks: " << error.what() << '\n';
        return 1;
    }
}
