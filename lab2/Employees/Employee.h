#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
protected:
    std::string employeeId;
    std::string name;
    std::string phone;
    std::string email;
    std::string position;
    double salary;
    std::string hireDate;
    std::string department;

public:
    Employee(const std::string& id, const std::string& name,
        const std::string& phone, const std::string& email,
        const std::string& position, double salary,
        const std::string& hireDate, const std::string& department);
    virtual ~Employee() = default;

    virtual double calculateBonus() const;
    virtual void promote(const std::string& newPosition);
    virtual void displayInfo() const;

    // Геттеры
    std::string getEmployeeId() const { return employeeId; }
    std::string getName() const { return name; }
    std::string getPosition() const { return position; }
    double getSalary() const { return salary; }
    std::string getDepartment() const { return department; }
};

#endif