#include "LogisticsManager.h"
#include "Route.h"
#include "Order.h"
#include "Warehouse.h"

LogisticsManager::LogisticsManager(const std::string& id, const std::string& name,
    const std::string& phone, const std::string& email,
    double salary, const std::string& hireDate)
    : Employee(id, name, phone, email, "Logistics Manager", salary, hireDate, "Logistics"),
    totalDistanceOptimized(0), deliveriesCoordinated(0) {
}

void LogisticsManager::optimizeDeliveryRoute(Route* route) {
    if (route) {
        route->calculateRoute();
        optimizedRoutes.push_back(route);
        totalDistanceOptimized += route->getTotalDistance();
    }
}

void LogisticsManager::coordinateOrderFulfillment(Order* order) {
    if (order) {
        managedOrders.push_back(order);
        deliveriesCoordinated++;
    }
}

void LogisticsManager::manageWarehouseOperations(Warehouse* warehouse) {
    if (warehouse) {
        managedWarehouses.push_back(warehouse);
    }
}

double LogisticsManager::calculateBonus() const {
    return Employee::calculateBonus() + (deliveriesCoordinated * 5) + (totalDistanceOptimized * 0.01);
}

double LogisticsManager::calculateCostSavings() const {
    return totalDistanceOptimized * 0.5; // Предполагаемая экономия $0.5 за км
}