#ifndef LOGISTICSMANAGER_H
#define LOGISTICSMANAGER_H

#include "Employee.h"
#include <vector>

class Route;
class Order;
class Warehouse;

class LogisticsManager : public Employee {
private:
    std::vector<Route*> optimizedRoutes;
    std::vector<Order*> managedOrders;
    std::vector<Warehouse*> managedWarehouses;
    double totalDistanceOptimized;
    int deliveriesCoordinated;

public:
    LogisticsManager(const std::string& id, const std::string& name, const std::string& phone,
        const std::string& email, double salary, const std::string& hireDate);

    void optimizeDeliveryRoute(Route* route);
    void coordinateOrderFulfillment(Order* order);
    void manageWarehouseOperations(Warehouse* warehouse);
    double calculateBonus() const override;
    double calculateCostSavings() const;

    int getDeliveriesCoordinated() const { return deliveriesCoordinated; }
};
#endif