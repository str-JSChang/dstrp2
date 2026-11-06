#include "task2.hpp"
#include "scaffold.hpp"
#include "task1.hpp"
#include "task3.hpp"

namespace campus {

RequestQueue::~RequestQueue() {
    while (head_) {
        Node* old = head_;
        head_ = head_->next;
        delete old;
    }
}

// TODO: Implement sorted insertion: Urgent before Normal, then increasing sequence.
bool RequestQueue::insert(const ServiceRequest&) { notImplemented("Insert request"); return false; }
ServiceRequest* RequestQueue::find(const std::string&) { notImplemented("Find request"); return nullptr; }
const ServiceRequest* RequestQueue::find(const std::string&) const { notImplemented("Find request"); return nullptr; }
const ServiceRequest* RequestQueue::nextPending() const { notImplemented("Select next pending request"); return nullptr; }
bool RequestQueue::remove(const std::string&) { notImplemented("Remove request"); return false; }
bool RequestQueue::hasActiveForParcel(const std::string&) const { notImplemented("Check active parcel requests"); return false; }
void RequestQueue::displayActive() const { notImplemented("Display active request queue"); }

// TODO: Use parcels_.findParcel; reject invalid recipients, terminal parcels and
// duplicate active requests. Generate ID, timestamp and FIFO tie-break sequence.
bool ServiceModule::createRequest(ServiceRequest) { notImplemented("Create service request"); return false; }
void ServiceModule::displayActiveRequests() const { notImplemented("Display active requests"); }
const ServiceRequest* ServiceModule::findRequest(const std::string&) const { notImplemented("Search service request"); return nullptr; }
const ServiceRequest* ServiceModule::nextRequest() const { notImplemented("Select next service request"); return nullptr; }

// TODO: Require a valid assigned resource for collection/delivery before processing.
bool ServiceModule::processRequest(const std::string&) { notImplemented("Process service request"); return false; }

// TODO: Validate outcome and recipient; update the parcel, save outcome details,
// and release the resource. Roll back changes if a dependent operation fails.
bool ServiceModule::completeRequest(const std::string&, RequestStatus, const std::string&, ResourceModule&) {
    notImplemented("Complete service request"); return false;
}
bool ServiceModule::cancelRequest(const std::string&, ResourceModule&) { notImplemented("Cancel service request"); return false; }
bool ServiceModule::removeTerminalRequest(const std::string&) { notImplemented("Remove terminal request"); return false; }
bool ServiceModule::hasActiveRequestForParcel(const std::string&) const { notImplemented("Check active requests"); return false; }

// TODO: Reject terminal/already assigned requests; maintain request status on attach
// and detach. These hooks form one transaction with Task 3's resource changes.
bool ServiceModule::attachResource(const std::string&, const std::string&) { notImplemented("Attach resource to request"); return false; }
bool ServiceModule::detachResource(const std::string&) { notImplemented("Detach resource from request"); return false; }

} // namespace campus
