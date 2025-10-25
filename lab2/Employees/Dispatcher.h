#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <string>
#include <vector>
#include "Employee.h"

class Order;
class Driver;
class Vehicle;

class Dispatcher : public Employee {
private:
    std::vector<Order*> pendingOrders;
    std::vector<Driver*> availableDrivers;

public:
    Dispatcher(const std::string& name, const std::string& phone);
    
    // Переопределение виртуальных методов
    double calculateBonus() const override;
    void displayInfo() const override;

    void receiveOrder(Order* order);
    void assignOrderToDriver(Order* order, Driver* driver);
    Vehicle* findSuitableVehicle(Order* order);
    void updateOrderStatus(Order* order, const std::string& status);

    int getPendingOrdersCount() const { return pendingOrders.size(); }
    int getAvailableDriversCount() const { return availableDrivers.size(); }
};

#endif
