
#include "ArchiveWorker.h"

ArchiveWorker::ArchiveWorker(int id, const string & name, const string & position,
    double salary, const shared_ptr<Department>&department)
    : Employee(id, name, position, salary, department) {
}

bool ArchiveWorker::canAccessArchive() const {
    return true;
}

string ArchiveWorker::getArchiveWorkerInfo() const {
    return "Archive Worker: " + getName();
}
