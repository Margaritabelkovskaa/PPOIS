#ifndef ARCHIVEWORKER_H
#define ARCHIVEWORKER_H

#include "Employee.h"

class ArchiveWorker : public Employee {
public:
    ArchiveWorker(int id, const string& name, const string& position,
        double salary, const shared_ptr<Department>& department);

    bool canAccessArchive() const;
    string getArchiveWorkerInfo() const;
};
#endif


