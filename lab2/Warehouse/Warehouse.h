#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <vector>
#include "Address.h"

class Cargo;

class Warehouse {
private:
    std::string name;
    Address* address;
    double totalCapacity;
    double usedCapacity;
    std::vector<Cargo*> storedCargo;
    bool hasRefrigeration;

public:
    Warehouse(const std::string& name, Address* address,
        double capacity, bool refrigeration);
    ~Warehouse();

    bool storeCargo(Cargo* cargo);
    Cargo* retrieveCargo(const std::string& cargoId);
    double getAvailableSpace() const;
    bool canStoreCargo(double volume) const;

    std::string getName() const { return name; }
    double getTotalCapacity() const { return totalCapacity; }
    double getUsedCapacity() const { return usedCapacity; }
};

#endif