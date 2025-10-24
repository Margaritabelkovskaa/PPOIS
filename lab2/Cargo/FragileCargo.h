#ifndef FRAGILECARGO_H
#define FRAGILECARGO_H

#include "Cargo.h"
#include <string>

class FragileCargo : public Cargo {
private:
    double fragilityLevel;            // ������� ��������� (1-10)
    double maxAllowedGForce;          // ������������ ���������� ��������� (g)
    std::string handlingInstructions; // ���������� �� ���������
    bool requiresCushioning;          // ��������� �����������
    double cushioningThickness;       // ������� ����������� (��)
    bool requiresUprightPosition;     // ��������� ������������ ���������
    std::string stackingRestrictions; // ����������� �� ��������������
    double insuranceMultiplier;       // ��������� ���������

public:
    FragileCargo(const std::string& desc, double weight, double volume,
        const std::string& type, bool refrigeration,
        double fragilityLevel, double maxGForce,
        const std::string& instructions, bool cushioning,
        double cushionThickness, bool uprightPosition,
        const std::string& stacking, double insuranceMultiplier);

    // ����������� ������ ��� ������� ������
    double calculateFragilityFactor() const;
    bool validatePackaging() const;
    double calculateRequiredCushioning() const;
    std::string generateHandlingGuidelines() const;
    double calculateFragileSurcharge(double baseRate) const;
    bool requiresSpecialPackaging() const;
    double getInsuranceMultiplier() const;

    // �������
    double getFragilityLevel() const { return fragilityLevel; }
    double getMaxAllowedGForce() const { return maxAllowedGForce; }
    bool getRequiresUprightPosition() const { return requiresUprightPosition; }
    std::string getHandlingInstructions() const { return handlingInstructions; }
};

#endif