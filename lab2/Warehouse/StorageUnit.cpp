#include "StorageUnit.h"

StorageUnit::StorageUnit(const std::string& id, const std::string& name, double capacity)
    : unitId(id), name(name), capacity(capacity), usedSpace(0) {
}

double StorageUnit::getAvailableSpace() const {
    return capacity - usedSpace;
}

bool StorageUnit::canStore(double volume) const {
    return usedSpace + volume <= capacity;
}

double StorageUnit::calculateUtilization() const {
    return (usedSpace / capacity) * 100.0;
}

// StorageZone методы
StorageZone::StorageZone(const std::string& id, const std::string& name, double capacity,
    const std::string& type, const std::string& temp, bool specialAccess)
    : StorageUnit(id, name, capacity), zoneType(type), temperatureRange(temp),
    requiresSpecialAccess(specialAccess) {
}

bool StorageZone::canStoreProduct(const std::string& productType) const {
    return true;
}

bool StorageZone::requiresTemperatureControl() const {
    return !temperatureRange.empty();
}

// Rack методы
Rack::Rack(const std::string& id, int number, double capacity)
    : StorageUnit(id, "Rack " + std::to_string(number), capacity), rackNumber(number) {
}