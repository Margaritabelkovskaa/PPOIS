#ifndef STORAGEUNIT_H
#define STORAGEUNIT_H

#include <string>

class StorageUnit {
protected:
    std::string unitId;
    std::string name;
    double capacity;
    double usedSpace;

public:
    StorageUnit(const std::string& id, const std::string& name, double capacity);
    virtual ~StorageUnit() = default;

    double getAvailableSpace() const;
    bool canStore(double volume) const;
    virtual double calculateUtilization() const;

    std::string getUnitId() const { return unitId; }
    double getCapacity() const { return capacity; }
};

class StorageZone : public StorageUnit {
private:
    std::string zoneType;
    std::string temperatureRange;
    bool requiresSpecialAccess;

public:
    StorageZone(const std::string& id, const std::string& name, double capacity,
        const std::string& type, const std::string& temp, bool specialAccess);

    bool canStoreProduct(const std::string& productType) const;
    bool requiresTemperatureControl() const;

    std::string getZoneType() const { return zoneType; }
};

class Rack : public StorageUnit {
private:
    int rackNumber;

public:
    Rack(const std::string& id, int number, double capacity);

    int getRackNumber() const { return rackNumber; }
};

#endif