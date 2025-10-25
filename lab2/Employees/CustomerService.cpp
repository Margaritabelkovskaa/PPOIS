#include "CustomerService.h"
#include "Client.h"
#include "Order.h"

CustomerService::CustomerService(const std::string& id, const std::string& name,
    const std::string& phone, const std::string& email,
    double salary, const std::string& hireDate,
    const std::string& specialization)
    : Employee(id, name, phone, email, "Customer Service", salary, hireDate, "Customer Support"),
    resolvedComplaints(0), customerSatisfactionRate(85.0), serviceSpecialization(specialization) {
}

void CustomerService::handleCustomerInquiry(Client* client, const std::string& inquiry) {
    if (client) {
        assistedClients.push_back(client);
        std::cout << "Handling inquiry from " << client->getName() << ": " << inquiry << std::endl;
    }
}

void CustomerService::processOrderComplaint(Order* order, const std::string& complaint) {
    if (order) {
        handledOrders.push_back(order);
        resolvedComplaints++;
        std::cout << "Processing complaint for order " << order->getOrderId() << std::endl;
    }
}

void CustomerService::provideTrackingInformation(Order* order) {
    if (order) {
        std::cout << "Providing tracking info for order " << order->getOrderId()
            << " - Status: " << order->getStatus() << std::endl;
    }
}

double CustomerService::calculateBonus() const {
    return Employee::calculateBonus() + (resolvedComplaints * 10) + (customerSatisfactionRate * 0.5);
}

void CustomerService::updateCustomerSatisfaction(double rating) {
    customerSatisfactionRate = (customerSatisfactionRate + rating) / 2;
}