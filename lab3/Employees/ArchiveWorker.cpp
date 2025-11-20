
#include "ArchiveWorker.h"

ArchiveWorker::ArchiveWorker(int id, const std::string& name, const std::string& position,
    double salary, const std::shared_ptr<Department>& department,
    bool hasAccessToRareMaterials)
    : Employee(id, name, position, salary, department),
    hasAccessToRareMaterials(hasAccessToRareMaterials) {
}

bool ArchiveWorker::canProcessLoans() const {
    return false; // Работники архива не могут обрабатывать займы
}

std::string ArchiveWorker::getRole() const {
    return "Archive Worker";
}

bool ArchiveWorker::canAccessRareMaterials() const {
    return hasAccessToRareMaterials;
}

bool ArchiveWorker::canRestoreDocuments() const {
    return true;
}

void ArchiveWorker::grantRareMaterialsAccess(bool access) {
    hasAccessToRareMaterials = access;
}
