#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Client;
class Order;

class Payment {
private:
    std::string paymentId;
    Client* client;
    Order* order;
    double amount;
    std::string paymentDate;
    std::string status;
    std::string method;

public:
    Payment(const std::string& id, Client* client, Order* order,
        double amount, const std::string& method);

    bool processPayment();
    void refund();
    bool isProcessed() const;

    std::string getPaymentId() const { return paymentId; }
    double getAmount() const { return amount; }
    std::string getStatus() const { return status; }
};

#endif