#include "HRManager.h"
#include "Employee.h"

HRManager::HRManager(const std::string& id, const std::string& name, const std::string& phone,
    const std::string& email, double salary, const std::string& hireDate)
    : Employee(id, name, phone, email, "HR Manager", salary, hireDate, "Human Resources"),
    employeesHired(0), recruitmentBudget(50000.0) {
}

void HRManager::hireEmployee(Employee* employee) {
    hiredEmployees.push_back(employee);
    employeesHired++;
    recruitmentBudget -= 1000; // Стоимость найма
}

void HRManager::conductInterview(const std::string& candidateName) {
    std::cout << "Conducting interview with candidate: " << candidateName << std::endl;
}

void HRManager::processSalaryReview(Employee* employee, double newSalary) {
    if (employee) {
        // Логика пересмотра зарплаты
        std::cout << "Processing salary review for " << employee->getName() << std::endl;
    }
}

double HRManager::calculateBonus() const {
    return Employee::calculateBonus() + (employeesHired * 100);
}

void HRManager::generateHRReport() const {
    std::cout << "HR Report - Employees Hired: " << employeesHired
        << ", Remaining Budget: $" << recruitmentBudget << std::endl;
}