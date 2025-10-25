#ifndef INVOICE_H
#define INVOICE_H

#include <string>

class Client;
class Order;

class Invoice {
private:
    std::string invoiceNumber;
    Client* client;
    Order* order;
    std::string issueDate;
    std::string dueDate;
    double amount;
    std::string status;

public:
    Invoice(const std::string& number, Client* client, Order* order,
        double amount, const std::string& dueDate);

    void markAsPaid();
    bool isOverdue() const;
    double calculateLateFee() const;

    std::string getInvoiceNumber() const { return invoiceNumber; }
    double getAmount() const { return amount; }
    std::string getStatus() const { return status; }
};

#endif