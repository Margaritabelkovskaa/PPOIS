#pragma once
#include <string>
#include <iostream>

class Employee {
private:
    std::string name;
    int age;
    double salary;

public:
    Employee() : name(""), age(0), salary(0.0) {}
    Employee(const std::string& n, int a, double s) : name(n), age(a), salary(s) {}

    bool operator<(const Employee& other) const {
        return salary < other.salary;
    }

    bool operator>(const Employee& other) const {
        return salary > other.salary;
    }

    bool operator<=(const Employee& other) const {
        return salary <= other.salary;
    }

    bool operator>=(const Employee& other) const {
        return salary >= other.salary;
    }

    bool operator==(const Employee& other) const {
        return salary == other.salary;
    }

    double getSalary() const { return salary; }
    std::string getName() const { return name; }
    int getAge() const { return age; }

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << "Employee{name: " << employee.name << ", age: " << employee.age << ", salary: " << employee.salary << "}";
        return os;
    }
};