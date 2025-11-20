#include "Librarian.h"

Librarian::Librarian(int id, const std::string& name, const std::string& position,
    double salary, const std::shared_ptr<Department>& department)
    : Employee(id, name, position, salary, department) {
}

bool Librarian::canProcessLoans() const {
    return true; // Библиотекари могут обрабатывать займы
}

std::string Librarian::getRole() const {
    return "Librarian";
}

bool Librarian::canManageCatalog() const {
    return true;
}

bool Librarian::canAssistReaders() const {
    return true;
}