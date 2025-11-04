#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double trailerCapacity;
    bool hasRefrigeration;
    int axleCount;

public:
    Truck(const std::string& plate, const std::string& model,
        double capacity, double trailerCap, bool refrigeration, int axles);

    double getTotalCapacity() const;
    void attachTrailer();
    void detachTrailer();

    double getTrailerCapacity() const { return trailerCapacity; }
    bool getHasRefrigeration() const { return hasRefrigeration; }
};

#endif