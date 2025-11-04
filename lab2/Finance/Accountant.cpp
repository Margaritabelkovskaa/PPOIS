#include "Accountant.h"
#include "Payment.h"
#include "Salary.h"
#include "Driver.h"
#include "Order.h"

Accountant::Accountant(const std::string& name, const std::string& phone)
    : name(name), phone(phone) {
}

void Accountant::processPayment(Payment* payment) {
    if (payment->processPayment()) {
        processedPayments.push_back(payment);
    }
}

void Accountant::calculateSalary(Driver* driver, int hours) {
    double salary = driver->calculateSalary(hours);
    // Логика расчета зарплаты
}

void Accountant::generateInvoice(Order* order) {
    // Генерация счета
}

double Accountant::calculateMonthlyRevenue() const {
    double total = 0;
    for (auto payment : processedPayments) {
        total += payment->getAmount();
    }
    return total;
}