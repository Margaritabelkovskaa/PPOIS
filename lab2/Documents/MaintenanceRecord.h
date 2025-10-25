#ifndef MAINTENANCERECORD_H
#define MAINTENANCERECORD_H

#include <string>

class Vehicle;
class Mechanic;

class MaintenanceRecord {
private:
    std::string recordId;
    Vehicle* vehicle;
    Mechanic* mechanic;
    std::string maintenanceDate;
    std::string description;
    double cost;
    std::string type;

public:
    MaintenanceRecord(const std::string& id, Vehicle* vehicle, Mechanic* mechanic,
        const std::string& date, const std::string& desc,
        double cost, const std::string& type);

    bool isRecent() const;
    double getCostPerMile() const;

    std::string getRecordId() const { return recordId; }
    double getCost() const { return cost; }
};

#endif