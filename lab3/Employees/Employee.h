
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Department;
class Loan;

class Employee {
private:
    int employeeId;
    string name;
    string position;
    string hireDate;
    double salary;
    shared_ptr<Department> department;
    vector<shared_ptr<Loan>> processedLoans;
    int yearsOfService;

public:
    Employee(int id, const string& name, const string& position,
        double salary, const shared_ptr<Department>& department);

    int calculateYearsOfService() const;
    bool isEligibleForPromotion() const;
    double calculateBonus() const;
    bool validateEmployeeData() const;
    bool canProcessLoan() const;
    double calculateProductivity() const;

    void addProcessedLoan(const shared_ptr<Loan>& loan);
    void setDepartment(const shared_ptr<Department>& dept);
    void updatePosition(const string& newPosition);

    int getEmployeeId() const;
    string getName() const;
    string getPosition() const;
    double getSalary() const;
    int getProcessedLoansCount() const;
};

#endif