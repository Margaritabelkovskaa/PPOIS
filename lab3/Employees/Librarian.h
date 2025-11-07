#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Employee.h"

class Librarian : public Employee {
public:
    Librarian(int id, const string& name, const string& position,
        double salary, const shared_ptr<Department>& department);

    bool canProcessLoan() const;
    string getLibrarianInfo() const;
};
#endif


