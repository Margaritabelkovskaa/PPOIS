
#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Employee.h"

class Librarian : public Employee {
public:
    Librarian(int id, const std::string& name, const std::string& position,
        double salary, const std::shared_ptr<Department>& department);

    bool canProcessLoans() const override;
    std::string getRole() const override;

    bool canManageCatalog() const;
    bool canAssistReaders() const;
};

#endif
