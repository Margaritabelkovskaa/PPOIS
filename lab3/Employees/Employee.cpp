#include "Employee.h"
#include "Department.h"

Employee::Employee(int id, const std::string& name, const std::string& position,
    double salary, const std::shared_ptr<Department>& department)
    : employeeId(id), name(name), position(position), salary(salary), department(department) {
}

// Геттеры
int Employee::getEmployeeId() const { return employeeId; }
std::string Employee::getName() const { return name; }
std::string Employee::getPosition() const { return position; }
double Employee::getSalary() const { return salary; }
std::shared_ptr<Department> Employee::getDepartment() const { return department; }

// Сеттеры
void Employee::setPosition(const std::string& newPosition) {
    position = newPosition;
}

void Employee::setSalary(double newSalary) {
    salary = newSalary;
}

void Employee::setDepartment(const std::shared_ptr<Department>& dept) {
    department = dept;
}