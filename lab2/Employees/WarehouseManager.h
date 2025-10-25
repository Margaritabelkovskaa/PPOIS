#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include "Employee.h"
#include <vector>

class Warehouse;
class Cargo;
class StorageUnit;

class WarehouseManager : public Employee {
private:
    std::vector<Warehouse*> managedWarehouses;
    std::vector<Cargo*> inventoryItems;
    double totalStorageCapacity;
    double currentUtilization;
    int shipmentsProcessed;

public:
    WarehouseManager(const std::string& id, const std::string& name, const std::string& phone,
        const std::string& email, double salary, const std::string& hireDate);

    void manageInventory(Warehouse* warehouse);
    void processShipment(Cargo* cargo);
    void optimizeStorageLayout(StorageUnit* storageUnit);
    double calculateBonus() const override;
    double calculateStorageEfficiency() const;

    double getCurrentUtilization() const { return currentUtilization; }
    int getShipmentsProcessed() const { return shipmentsProcessed; }
};
#endif
