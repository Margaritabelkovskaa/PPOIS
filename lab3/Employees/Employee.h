// Employee.h - базовый класс для всех сотрудников
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <memory>

class Department;

class Employee {
protected:
    int employeeId;
    std::string name;
    std::string position;
    double salary;
    std::shared_ptr<Department> department;

public:
    Employee(int id, const std::string& name, const std::string& position,
        double salary, const std::shared_ptr<Department>& department);
    virtual ~Employee() = default;

    // Общие методы для всех сотрудников
    virtual bool canProcessLoans() const = 0;
    virtual std::string getRole() const = 0;

    // Геттеры
    int getEmployeeId() const;
    std::string getName() const;
    std::string getPosition() const;
    double getSalary() const;
    std::shared_ptr<Department> getDepartment() const;

    // Сеттеры
    void setPosition(const std::string& newPosition);
    void setSalary(double newSalary);
    void setDepartment(const std::shared_ptr<Department>& dept);
};

#endif