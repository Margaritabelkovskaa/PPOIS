#include "Employee.h"
#include "Department.h"
#include "Loan.h"

Employee::Employee(int id, const string& name, const string& position,
    double salary, const shared_ptr<Department>& department)
    : employeeId(id), name(name), position(position), salary(salary),
    department(department), yearsOfService(0) {
}

int Employee::calculateYearsOfService() const {
    if (hireDate.length() >= 4) {
        int hireYear = stoi(hireDate.substr(0, 4));
        return 2024 - hireYear;
    }
    return 0;
}

bool Employee::isEligibleForPromotion() const {
    return yearsOfService >= 2 && processedLoans.size() > 50;
}

double Employee::calculateBonus() const {
    return salary * 0.1 * (yearsOfService / 2.0);
}

bool Employee::validateEmployeeData() const {
    return !name.empty() && !position.empty() && salary > 0 && employeeId > 0;
}

bool Employee::canProcessLoan() const {
    return position == "librarian" || position == "assistant";
}

double Employee::calculateProductivity() const {
    return processedLoans.size() * 1.5 + yearsOfService * 0.5;
}

void Employee::addProcessedLoan(const shared_ptr<Loan>& loan) {
    processedLoans.push_back(loan);
}

void Employee::setDepartment(const shared_ptr<Department>& dept) {
    department = dept;
}

void Employee::updatePosition(const string& newPosition) {
    position = newPosition;
}

int Employee::getEmployeeId() const {
    return employeeId;
}

string Employee::getName() const {
    return name;
}

string Employee::getPosition() const {
    return position;
}

double Employee::getSalary() const {
    return salary;
}

int Employee::getProcessedLoansCount() const {
    return processedLoans.size();
}