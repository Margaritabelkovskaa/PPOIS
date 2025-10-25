#include "TrackingSystem.h"
#include "Vehicle.h"
#include "GPSPosition.h"

TrackingSystem::TrackingSystem(const std::string& name)
    : systemName(name) {
}

void TrackingSystem::addVehicleToTrack(Vehicle* vehicle) {
    trackedVehicles.push_back(vehicle);
}

GPSPosition* TrackingSystem::getVehiclePosition(Vehicle* vehicle) const {
    // ¬озвращает текущую позицию транспортного средства
    return nullptr;
}

void TrackingSystem::updateAllPositions() {
    // ќбновл€ет позиции всех отслеживаемых транспортных средств
}

std::vector<Vehicle*> TrackingSystem::findVehiclesNearLocation(double lat, double lon, double radius) const {
    std::vector<Vehicle*> nearbyVehicles;
    // Ћогика поиска транспортных средств р€дом с локацией
    return nearbyVehicles;
}