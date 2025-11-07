#include "Librarian.h"

Librarian::Librarian(int id, const string& name, const string& position,
    double salary, const shared_ptr<Department>& department)
    : Employee(id, name, position, salary, department) {
}

bool Librarian::canProcessLoan() const {
    return true;
}

string Librarian::getLibrarianInfo() const {
    return "Librarian: " + getName();
}