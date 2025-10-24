#ifndef CARGO_H
#define CARGO_H

#include <string>

class Cargo {
private:
    std::string description;
    double weight;
    double volume;
    std::string type;
    bool isFragile;
    bool requiresRefrigeration;

public:
    Cargo(const std::string& desc, double weight, double volume,
        const std::string& type, bool fragile = false, bool refrigeration = false);

    double calculateShippingCost(double baseRate) const;
    bool requiresSpecialHandling() const;

    std::string getDescription() const { return description; }
    double getWeight() const { return weight; }
    std::string getType() const { return type; }
};

#endif
