#include "Warehouse.h"
#include "Cargo.h"

Warehouse::Warehouse(const std::string& name, Address* address,
    double capacity, bool refrigeration)
    : name(name), address(address), totalCapacity(capacity),
    usedCapacity(0), hasRefrigeration(refrigeration) {
}

Warehouse::~Warehouse() {
    delete address;
    for (auto cargo : storedCargo) {
        delete cargo;
    }
}

bool Warehouse::storeCargo(Cargo* cargo) {
    if (canStoreCargo(cargo->getWeight())) {
        storedCargo.push_back(cargo);
        usedCapacity += cargo->getWeight();
        return true;
    }
    return false;
}

Cargo* Warehouse::retrieveCargo(const std::string& cargoId) {
    for (auto it = storedCargo.begin(); it != storedCargo.end(); ++it) {
        if ((*it)->getDescription() == cargoId) {
            Cargo* cargo = *it;
            storedCargo.erase(it);
            usedCapacity -= cargo->getWeight();
            return cargo;
        }
    }
    return nullptr;
}

double Warehouse::getAvailableSpace() const {
    return totalCapacity - usedCapacity;
}

bool Warehouse::canStoreCargo(double volume) const {
    return usedCapacity + volume <= totalCapacity;
}