#include "Dispatcher.h"
#include "Order.h"
#include "Driver.h"
#include "Vehicle.h"
#include <iostream>
#include <sstream>
#include <algorithm>

Dispatcher::Dispatcher(const std::string& name, const std::string& phone)
    : Employee("DSP_" + std::to_string(rand() % 10000), name, phone,
               name + "@company.com", "Dispatcher", 40000.0,
               "2024-01-01", "Operations") {
}

double Dispatcher::calculateBonus() const {
    // Диспетчеры получают бонус 12% + за эффективность работы
    double baseBonus = salary * 0.12;
    double efficiencyBonus = (100 - pendingOrders.size()) * 10; // Меньше заказов в ожидании - больше бонус
    return baseBonus + std::max(0.0, efficiencyBonus);
}

void Dispatcher::displayInfo() const {
    std::cout << "Dispatcher ID: " << employeeId << "\n"
              << "Name: " << name << "\n"
              << "Phone: " << phone << "\n"
              << "Email: " << email << "\n"
              << "Position: " << position << "\n"
              << "Department: " << department << "\n"
              << "Salary: $" << salary << "\n"
              << "Pending Orders: " << pendingOrders.size() << "\n"
              << "Available Drivers: " << availableDrivers.size() << "\n";
}

void Dispatcher::receiveOrder(Order* order) {
    if (order) {
        pendingOrders.push_back(order);
        std::cout << "Order #" << order->getOrderId() << " received by dispatcher " << name << "\n";
    }
}

void Dispatcher::assignOrderToDriver(Order* order, Driver* driver) {
    if (driver && driver->getIsAvailable() && order) {
        order->assignDriver(driver);
        driver->setAvailability(false);
        
        // Убираем заказ из списка ожидания
        auto it = std::find(pendingOrders.begin(), pendingOrders.end(), order);
        if (it != pendingOrders.end()) {
            pendingOrders.erase(it);
        }
        
        std::cout << "Order #" << order->getOrderId() 
                  << " assigned to driver " << driver->getName() << "\n";
    }
}

Vehicle* Dispatcher::findSuitableVehicle(Order* order) {
    if (!order || !order->getCargo()) {
        return nullptr;
    }

    std::cout << "Searching for suitable vehicle for order #" 
              << order->getOrderId() << "\n";
    return nullptr;
}

void Dispatcher::updateOrderStatus(Order* order, const std::string& status) {
    if (order) {
        order->updateStatus(status);
        std::cout << "Order #" << order->getOrderId() 
                  << " status updated to: " << status << "\n";
        
        // Если заказ доставлен, освобождаем водителя
        if (status == "Delivered" && order->getDriver()) {
            order->getDriver()->setAvailability(true);
        }
    }
}

void Dispatcher::updateOrderStatus(Order* order, const std::string& status) {
    order->updateStatus(status);

}
