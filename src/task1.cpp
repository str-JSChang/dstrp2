#include "task1.hpp"
#include "scaffold.hpp"
#include "task2.hpp"

namespace campus {

ParcelRecords::~ParcelRecords() {
    while (head_) {
        Node* old = head_;
        head_ = head_->next;
        delete old;
    }
}
IntakeQueue::~IntakeQueue() {
    while (front_) {
        Node* old = front_;
        front_ = front_->next;
        delete old;
    }
    rear_ = nullptr;
}

// TODO: Replace stubs with the manual linked-list and queue algorithms.
// Parameters are intentionally unnamed until used, keeping the scaffold warning-free.
bool ParcelRecords::insert(const Parcel&) { notImplemented("Insert parcel record"); return false; }
Parcel* ParcelRecords::find(const std::string&) { notImplemented("Find parcel record"); return nullptr; }
const Parcel* ParcelRecords::find(const std::string&) const { notImplemented("Find parcel record"); return nullptr; }
bool ParcelRecords::remove(const std::string&) { notImplemented("Remove parcel record"); return false; }
void ParcelRecords::display() const { notImplemented("Display parcel records"); }
bool IntakeQueue::enqueue(const std::string&) { notImplemented("Enqueue parcel ID"); return false; }
bool IntakeQueue::dequeue(std::string&) { notImplemented("Dequeue parcel ID"); return false; }
bool IntakeQueue::peek(std::string&) const { notImplemented("Peek intake queue"); return false; }
void IntakeQueue::display() const { notImplemented("Display intake queue"); }

// TODO: Validate required fields and tracking duplicates; generate a unique parcel ID
// and timestamp. If queue insertion fails, roll back the inserted parcel record.
bool ParcelModule::registerParcel(Parcel) { notImplemented("Register parcel"); return false; }
void ParcelModule::displayParcels() const { notImplemented("Display parcels"); }
const Parcel* ParcelModule::findParcel(const std::string&) const { notImplemented("Search parcel"); return nullptr; }

// TODO: Preserve the ID; validate edits and prevent illegal status transitions.
bool ParcelModule::updateParcel(const std::string&, const Parcel&) { notImplemented("Update parcel"); return false; }

// TODO: Only remove cancelled records without active requests; also remove any
// waiting entry, or safely skip stale IDs during intake processing.
bool ParcelModule::removeParcel(const std::string&, const ServiceModule&) { notImplemented("Remove parcel"); return false; }

// TODO: Peek FIFO head, validate state, choose route and create a Task 2 request
// where needed. Hold routes create no request. Commit status/dequeue only after
// successful routing; leave the parcel waiting on failure. Preserve the record.
bool ParcelModule::processNext(Route, ServiceModule&) { notImplemented("Process next parcel"); return false; }
void ParcelModule::displayWaiting() const { notImplemented("Display waiting parcels"); }
bool ParcelModule::updateStatus(const std::string&, ParcelStatus) { notImplemented("Update parcel status"); return false; }

} // namespace campus
