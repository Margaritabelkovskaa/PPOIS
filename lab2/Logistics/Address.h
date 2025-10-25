#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include "GPSPosition.h"

class GPSPosition;

class Address {
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;
    std::string country;
    GPSPosition* gpsPosition;

public:
    Address(const std::string& street, const std::string& city,
        const std::string& state, const std::string& zip,
        const std::string& country);
    ~Address();

    std::string getFullAddress() const;
    void setGPSPosition(GPSPosition* position);
    bool validate() const;

    std::string getCity() const { return city; }
    std::string getCountry() const { return country; }
    GPSPosition* getGPSPosition() const { return gpsPosition; }
};

#endif