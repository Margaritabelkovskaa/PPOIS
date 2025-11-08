#ifndef DANGEROUSСARGO_H
#define DANGEROUSCARGO_H

#include "Cargo.h"
#include <vector>
#include <string>

class DangerousCargo : public Cargo {
private:
    std::string hazardClass;
    std::string unNumber;
    bool requiresSpecialPermit;
    std::string emergencyContact;

public:
    DangerousCargo(const std::string& desc, double weight, 
                  const std::string& hazardClass, const std::string& unNumber);

    bool validateDocuments() const;
    double calculateRisk() const;
    bool needsSpecialVehicle() const;
    std::string getEmergencyInfo() const;

    std::string getHazardClass() const { return hazardClass; }
    std::string getUnNumber() const { return unNumber; }
};

#endif
