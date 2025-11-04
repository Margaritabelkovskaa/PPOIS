#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include <string>
#include <vector>
#include "Driver.h"
#include "Order.h"

class Payment;
class Salary;
class Invoice;

class Accountant {
private:
    std::string name;
    std::string phone;
    std::vector<Payment*> processedPayments;
    std::vector<Salary*> salaryRecords;

public:
    Accountant(const std::string& name, const std::string& phone);

    void processPayment(Payment* payment);
    void calculateSalary(Driver* driver, int hours);
    void generateInvoice(Order* order);
    double calculateMonthlyRevenue() const;

    std::string getName() const { return name; }
    int getProcessedPaymentsCount() const { return processedPayments.size(); }
};

#endif
