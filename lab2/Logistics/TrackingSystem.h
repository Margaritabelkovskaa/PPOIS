#ifndef TRACKINGSYSTEM_H
#define TRACKINGSYSTEM_H

#include <vector>
#include <string>

class Vehicle;
class GPSPosition;

class TrackingSystem {
private:
    std::vector<Vehicle*> trackedVehicles;
    std::string systemName;

public:
    TrackingSystem(const std::string& name);

    void addVehicleToTrack(Vehicle* vehicle);
    GPSPosition* getVehiclePosition(Vehicle* vehicle) const;
    void updateAllPositions();
    std::vector<Vehicle*> findVehiclesNearLocation(double lat, double lon, double radius) const;

    std::string getSystemName() const { return systemName; }
    int getTrackedVehiclesCount() const { return trackedVehicles.size(); }
};

#endif