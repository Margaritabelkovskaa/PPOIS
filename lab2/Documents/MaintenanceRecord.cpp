#include "MaintenanceRecord.h"
#include "Vehicle.h"
#include "Mechanic.h"

MaintenanceRecord::MaintenanceRecord(const std::string& id, Vehicle* vehicle,
    Mechanic* mechanic, const std::string& date, const std::string& desc,
    double cost, const std::string& type)
    : recordId(id), vehicle(vehicle), mechanic(mechanic), maintenanceDate(date),
    description(desc), cost(cost), type(type) {
}

bool MaintenanceRecord::isRecent() const {
    return true;
}

double MaintenanceRecord::getCostPerMile() const {
    return cost / 1000.0;
}