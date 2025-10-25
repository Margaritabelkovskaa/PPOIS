#include "Employee.h"

Employee::Employee(const std::string& id, const std::string& name,
    const std::string& phone, const std::string& email,
    const std::string& position, double salary,
    const std::string& hireDate, const std::string& department)
    : employeeId(id), name(name), phone(phone), email(email),
    position(position), salary(salary), hireDate(hireDate), department(department) {
}

double Employee::calculateBonus() const {
    return salary * 0.1; // 10% от зарплаты как базовый бонус
}

void Employee::promote(const std::string& newPosition) {
    position = newPosition;
    salary *= 1.15; // 15% повышение при продвижении
}

void Employee::displayInfo() const {
    std::cout << "Employee ID: " << employeeId << "\n"
        << "Name: " << name << "\n"
        << "Position: " << position << "\n"
        << "Department: " << department << "\n"
        << "Salary: $" << salary << "\n"
        << "Hire Date: " << hireDate << std::endl;
}