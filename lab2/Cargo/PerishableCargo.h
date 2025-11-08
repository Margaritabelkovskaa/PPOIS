#ifndef PERISHABLECARGO_H
#define PERISHABLECARGO_H

#include "Cargo.h"
#include <string>

class PerishableCargo : public Cargo {
private:
    double requiredTemperature;
    std::string expiryDate;
    int maxTransportTime;
    bool requiresRefrigeration;

public:
    PerishableCargo(const std::string& desc, double weight,
                   double reqTemp, const std::string& expiry, int maxTransport);

    bool isExpired() const;
    bool validateTemperature(double currentTemp) const;
    bool needsRefrigeration() const;
    std::string getStorageInfo() const;

    double getRequiredTemperature() const { return requiredTemperature; }
    std::string getExpiryDate() const { return expiryDate; }
    int getMaxTransportTime() const { return maxTransportTime; }
};

#endif
