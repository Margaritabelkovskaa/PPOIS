#include "Invoice.h"
#include "Client.h"
#include "Order.h"

Invoice::Invoice(const std::string& number, Client* client, Order* order,
    double amount, const std::string& dueDate)
    : invoiceNumber(number), client(client), order(order), amount(amount),
    issueDate("2024-01-01"), dueDate(dueDate), status("pending") {
}

void Invoice::markAsPaid() {
    status = "paid";
}

bool Invoice::isOverdue() const {
    return false;
}

double Invoice::calculateLateFee() const {
    return amount * 0.1;
}