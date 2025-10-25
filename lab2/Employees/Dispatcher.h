#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <string>
#include <vector>

class Order;
class Driver;
class Vehicle;

class Dispatcher {
private:
    std::string name;
    std::string phone;
    std::vector<Order*> pendingOrders;
    std::vector<Driver*> availableDrivers;

public:
    Dispatcher(const std::string& name, const std::string& phone);

    void receiveOrder(Order* order);
    void assignOrderToDriver(Order* order, Driver* driver);
    Vehicle* findSuitableVehicle(Order* order);
    void updateOrderStatus(Order* order, const std::string& status);

    std::string getName() const { return name; }
    int getPendingOrdersCount() const { return pendingOrders.size(); }
};

#endif