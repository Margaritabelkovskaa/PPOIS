#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include "Employee.h"

class Driver;
class Vehicle;
class Order;

class Manager : public Employee {
private:
    std::vector<Driver*> managedDrivers;
    std::vector<Vehicle*> managedVehicles;

public:
    Manager(const std::string& name, const std::string& phone,
        const std::string& email, const std::string& department);
    
    // Переопределение виртуальных методов
    double calculateBonus() const override;
    void promote(const std::string& newPosition) override;
    void displayInfo() const override;

    void assignDriverToOrder(Driver* driver, Order* order);
    void approveOrder(Order* order);
    void generateDailyReport() const;
    void addDriverToTeam(Driver* driver);
    void addVehicleToFleet(Vehicle* vehicle);

    int getTeamSize() const { return managedDrivers.size(); }
    int getFleetSize() const { return managedVehicles.size(); }
};

#endif
