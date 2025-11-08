#ifndef FRAGILECARGO_H
#define FRAGILECARGO_H

#include "Cargo.h"
#include <string>

class FragileCargo : public Cargo {
private:
    double fragilityLevel;           
    double maxAllowedGForce;          
    std::string handlingInstructions; 
    bool requiresSpecialPackaging;    

public:
    FragileCargo(const std::string& desc, double weight, 
                 double fragilityLevel, double maxGForce,
                 const std::string& instructions);

    double calculateFragilityFactor() const;
    bool validatePackaging() const;
    double calculateSurcharge(double baseRate) const;
    std::string getHandlingInfo() const;

    double getFragilityLevel() const { return fragilityLevel; }
    double getMaxGForce() const { return maxAllowedGForce; }
    std::string getInstructions() const { return handlingInstructions; }
};


#endif
