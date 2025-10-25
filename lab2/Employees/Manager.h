#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>

class Driver;
class Vehicle;
class Order;

class Manager {
private:
    std::string name;
    std::string phone;
    std::string email;
    std::vector<Driver*> managedDrivers;
    std::vector<Vehicle*> managedVehicles;
    std::string department;

public:
    Manager(const std::string& name, const std::string& phone,
        const std::string& email, const std::string& department);

    void assignDriverToOrder(Driver* driver, Order* order);
    void approveOrder(Order* order);
    void generateDailyReport() const;
    void addDriverToTeam(Driver* driver);
    void addVehicleToFleet(Vehicle* vehicle);

    std::string getName() const { return name; }
    std::string getDepartment() const { return department; }
    int getTeamSize() const { return managedDrivers.size(); }
};

#endif