#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include <memory>

class Employee;

class Department {
private:
    std::string name;
    std::string location;
    std::vector<std::shared_ptr<Employee>> employees;

public:
    Department(const std::string& name, const std::string& location);

    // Управление сотрудниками
    void addEmployee(const std::shared_ptr<Employee>& employee);
    bool removeEmployee(int employeeId);
    std::vector<std::shared_ptr<Employee>> getEmployees() const;

    // Информация об отделе
    int getEmployeeCount() const;
    std::string getContactInfo() const;

    // Геттеры
    std::string getName() const;
    std::string getLocation() const;
};

#endif