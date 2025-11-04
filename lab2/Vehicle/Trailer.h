#ifndef TRAILER_H
#define TRAILER_H

#include <string>

class Truck;

class Trailer {
private:
    std::string trailerId;
    std::string type;
    double capacity;
    double currentLoad;
    bool isAttached;
    Truck* attachedToTruck;
    bool hasRefrigeration;
    double length;
    double width;
    double height;

public:
    Trailer(const std::string& id, const std::string& type, double capacity,
        bool refrigeration, double length, double width, double height);

    void attachToTruck(Truck* truck);
    void detachFromTruck();
    bool loadCargo(double weight);
    void unloadCargo();
    double getAvailableCapacity() const;
    bool requiresSpecialLicense() const;

    std::string getTrailerId() const { return trailerId; }
    double getCapacity() const { return capacity; }
    bool getIsAttached() const { return isAttached; }
};
#endif