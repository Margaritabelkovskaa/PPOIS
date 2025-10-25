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
    // ���������� ������� ������� ������������� ��������
    return nullptr;
}

void TrackingSystem::updateAllPositions() {
    // ��������� ������� ���� ������������� ������������ �������
}

std::vector<Vehicle*> TrackingSystem::findVehiclesNearLocation(double lat, double lon, double radius) const {
    std::vector<Vehicle*> nearbyVehicles;
    // ������ ������ ������������ ������� ����� � ��������
    return nearbyVehicles;
}