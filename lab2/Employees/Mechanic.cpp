#include "Mechanic.h"
#include "Vehicle.h"
#include "MaintenanceRecord.h"

Mechanic::Mechanic(const std::string& name, const std::string& specialization)
    : name(name), specialization(specialization) {
}

void Mechanic::performMaintenance(Vehicle* vehicle, const std::string& description) {
    // Логика выполнения ТО
}

bool Mechanic::diagnoseProblem(Vehicle* vehicle) const {
    // Простая диагностика
    return vehicle->getCapacity() > 0; // Пример
}

void Mechanic::addVehicleToMaintenance(Vehicle* vehicle) {
    assignedVehicles.push_back(vehicle);
}