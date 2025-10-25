#include "Payment.h"
#include "Client.h"
#include "Order.h"

Payment::Payment(const std::string& id, Client* client, Order* order,
    double amount, const std::string& method)
    : paymentId(id), client(client), order(order), amount(amount),
    paymentDate("2024-01-01"), status("Pending"), method(method) {
   
}

bool Payment::processPayment() {
    if (client && client->makePayment(amount)) {
        status = "Completed";
        return true;
    }
    status = "Failed";
    return false;
}

void Payment::refund() {
    status = "Refunded";
}

bool Payment::isProcessed() const {
    return status == "Completed";
}