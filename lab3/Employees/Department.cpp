#include "Department.h"
#include "Employee.h"
#include <algorithm>

Department::Department(const std::string& name, const std::string& location)
    : name(name), location(location) {
}

void Department::addEmployee(const std::shared_ptr<Employee>& employee) {
    if (employee) {
        employees.push_back(employee);
    }
}

bool Department::removeEmployee(int employeeId) {
    auto it = std::remove_if(employees.begin(), employees.end(),
        [employeeId](const auto& emp) {
            return emp->getEmployeeId() == employeeId;
        });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
        return true;
    }
    return false;
}

std::vector<std::shared_ptr<Employee>> Department::getEmployees() const {
    return employees;
}

int Department::getEmployeeCount() const {
    return employees.size();
}

std::string Department::getContactInfo() const {
    return name + " - " + location;
}

std::string Department::getName() const { return name; }
std::string Department::getLocation() const { return location; }