
#ifndef ARCHIVEWORKER_H
#define ARCHIVEWORKER_H

#include "Employee.h"

class ArchiveWorker : public Employee {
private:
    bool hasAccessToRareMaterials;

public:
    ArchiveWorker(int id, const std::string& name, const std::string& position,
        double salary, const std::shared_ptr<Department>& department,
        bool hasAccessToRareMaterials = false);

    bool canProcessLoans() const override;
    std::string getRole() const override;

    bool canAccessRareMaterials() const;
    bool canRestoreDocuments() const;
    void grantRareMaterialsAccess(bool access);
};

#endif

