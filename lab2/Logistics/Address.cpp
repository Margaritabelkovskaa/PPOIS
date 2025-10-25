#include "Address.h"

Address::Address(const std::string& street, const std::string& city,
    const std::string& state, const std::string& zip,
    const std::string& country)
    : street(street), city(city), state(state), zipCode(zip),
    country(country), gpsPosition(nullptr) {
}

Address::~Address() {
    delete gpsPosition;
}

std::string Address::getFullAddress() const {
    return street + ", " + city + ", " + state + " " + zipCode + ", " + country;
}

void Address::setGPSPosition(GPSPosition* position) {
    delete gpsPosition;
    gpsPosition = position;
}

bool Address::validate() const {
    return !street.empty() && !city.empty() && !zipCode.empty();
}