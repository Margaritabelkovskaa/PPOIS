#include "FragileCargo.h"
#include <cmath>

FragileCargo::FragileCargo(const std::string& desc, double weight, double volume,
    const std::string& type, bool refrigeration,
    double fragilityLevel, double maxGForce,
    const std::string& instructions, bool cushioning,
    double cushionThickness, bool uprightPosition,
    const std::string& stacking, double insuranceMultiplier)
    : Cargo(desc, weight, volume, type, true, refrigeration), // ��� ������� ����� fragile=true
    fragilityLevel(fragilityLevel), maxAllowedGForce(maxGForce),
    handlingInstructions(instructions), requiresCushioning(cushioning),
    cushioningThickness(cushionThickness), requiresUprightPosition(uprightPosition),
    stackingRestrictions(stacking), insuranceMultiplier(insuranceMultiplier) {
}

double FragileCargo::calculateFragilityFactor() const {
    double factor = fragilityLevel / 10.0; // ������������ �� 0-1

    // ���� ����������� �� ���������
    if (maxAllowedGForce < 2.0) factor *= 1.5;
    else if (maxAllowedGForce < 5.0) factor *= 1.2;

    // ���� ���������� � ���������
    if (requiresUprightPosition) factor *= 1.3;

    return factor;
}

bool FragileCargo::validatePackaging() const {
    if (requiresCushioning && cushioningThickness < 2.0) {
        return false; // ����������� ������� ����������� 2 ��
    }

    if (fragilityLevel > 7.0 && !requiresCushioning) {
        return false; // ������� ��������� ������� �����������
    }

    return true;
}

double FragileCargo::calculateRequiredCushioning() const {
    double baseCushioning = 2.0; // ������� ������� 2 ��

    if (fragilityLevel > 8.0) {
        baseCushioning += 3.0; // +3 �� ��� ����� �������
    }
    else if (fragilityLevel > 5.0) {
        baseCushioning += 1.5; // +1.5 �� ��� �������
    }

    // ���� ���� - ������� ������� �������� ������� ������ �����������
    if (getWeight() > 50.0) {
        baseCushioning += getWeight() * 0.01;
    }

    return baseCushioning;
}

std::string FragileCargo::generateHandlingGuidelines() const {
    std::string guidelines = "Handling guidelines for fragile cargo: " + getDescription() + "\n";
    guidelines += "Fragility Level: " + std::to_string(fragilityLevel) + "/10\n";
    guidelines += "Max G-Force: " + std::to_string(maxAllowedGForce) + "g\n";

    if (requiresUprightPosition) {
        guidelines += "- MUST be kept in upright position\n";
    }

    if (requiresCushioning) {
        guidelines += "- Requires cushioning: " + std::to_string(cushioningThickness) + "cm\n";
    }

    if (!stackingRestrictions.empty()) {
        guidelines += "- Stacking: " + stackingRestrictions + "\n";
    }

    guidelines += "Special instructions: " + handlingInstructions + "\n";

    return guidelines;
}

double FragileCargo::calculateFragileSurcharge(double baseRate) const {
    double surcharge = 0.0;

    if (fragilityLevel > 7.0) {
        surcharge = 0.4; // 40% �������� ��� ����� �������
    }
    else if (fragilityLevel > 4.0) {
        surcharge = 0.25; // 25% �������� ��� �������
    }
    else {
        surcharge = 0.15; // 15% �������� ��� ������ �������
    }

    // �������������� �������� �� ����������� ����������
    if (requiresUprightPosition) surcharge += 0.1;
    if (requiresCushioning) surcharge += 0.05;

    return baseRate * surcharge;
}

bool FragileCargo::requiresSpecialPackaging() const {
    return fragilityLevel > 5.0 || requiresUprightPosition || requiresCushioning;
}

double FragileCargo::getInsuranceMultiplier() const {
    return insuranceMultiplier;
}