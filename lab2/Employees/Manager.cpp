#include "Manager.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Order.h"
#include <iostream>

Manager::Manager(const std::string& name, const std::string& phone,
    const std::string& email, const std::string& department)
    : name(name), phone(phone), email(email), department(department) {
}

void Manager::assignDriverToOrder(Driver* driver, Order* order) {
    if (driver && driver->getIsAvailable()) {
        order->assignDriver(driver);
    }
}

void Manager::approveOrder(Order* order) {
    order->updateStatus("Approved");
}

void Manager::generateDailyReport() const {
    std::cout << "Daily Report - Manager: " << name << std::endl;
    std::cout << "Team Size: " << managedDrivers.size() << std::endl;
    std::cout << "Fleet Size: " << managedVehicles.size() << std::endl;
}

void Manager::addDriverToTeam(Driver* driver) {
    managedDrivers.push_back(driver);
}

void Manager::addVehicleToFleet(Vehicle* vehicle) {
    managedVehicles.push_back(vehicle);
}