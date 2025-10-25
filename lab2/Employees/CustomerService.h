#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

#include "Employee.h"
#include <vector>

class Client;
class Order;

class CustomerService : public Employee {
private:
    std::vector<Client*> assistedClients;
    std::vector<Order*> handledOrders;
    int resolvedComplaints;
    double customerSatisfactionRate;
    std::string serviceSpecialization;

public:
    CustomerService(const std::string& id, const std::string& name, const std::string& phone,
        const std::string& email, double salary, const std::string& hireDate,
        const std::string& specialization);

    void handleCustomerInquiry(Client* client, const std::string& inquiry);
    void processOrderComplaint(Order* order, const std::string& complaint);
    void provideTrackingInformation(Order* order);
    double calculateBonus() const override;
    void updateCustomerSatisfaction(double rating);

    int getResolvedComplaints() const { return resolvedComplaints; }
    double getSatisfactionRate() const { return customerSatisfactionRate; }
};
#endif
