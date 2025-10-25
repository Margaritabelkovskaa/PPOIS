#include "Dispatcher.h"
#include "Order.h"
#include "Driver.h"
#include "Vehicle.h"

Dispatcher::Dispatcher(const std::string& name, const std::string& phone)
    : name(name), phone(phone) {
}

void Dispatcher::receiveOrder(Order* order) {
    pendingOrders.push_back(order);
}

void Dispatcher::assignOrderToDriver(Order* order, Driver* driver) {
    if (driver && driver->getIsAvailable()) {
        order->assignDriver(driver);
        driver->setAvailability(false);
    }
}

Vehicle* Dispatcher::findSuitableVehicle(Order* order) {
    // Логика подбора подходящего транспорта
    return nullptr;
}

void Dispatcher::updateOrderStatus(Order* order, const std::string& status) {
    order->updateStatus(status);
}