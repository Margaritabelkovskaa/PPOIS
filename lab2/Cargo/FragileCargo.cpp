#include "FragileCargo.h"
#include <cmath>

FragileCargo::FragileCargo(const std::string& desc, double weight, double volume,
    const std::string& type, bool refrigeration,
    double fragilityLevel, double maxGForce,
    const std::string& instructions, bool cushioning,
    double cushionThickness, bool uprightPosition,
    const std::string& stacking, double insuranceMultiplier)
    : Cargo(desc, weight, volume, type, true, refrigeration), // Все хрупкие грузы fragile=true
    fragilityLevel(fragilityLevel), maxAllowedGForce(maxGForce),
    handlingInstructions(instructions), requiresCushioning(cushioning),
    cushioningThickness(cushionThickness), requiresUprightPosition(uprightPosition),
    stackingRestrictions(stacking), insuranceMultiplier(insuranceMultiplier) {
}

double FragileCargo::calculateFragilityFactor() const {
    double factor = fragilityLevel / 10.0; // Нормализация до 0-1

    // Учет ограничений по ускорению
    if (maxAllowedGForce < 2.0) factor *= 1.5;
    else if (maxAllowedGForce < 5.0) factor *= 1.2;

    // Учет требований к положению
    if (requiresUprightPosition) factor *= 1.3;

    return factor;
}

bool FragileCargo::validatePackaging() const {
    if (requiresCushioning && cushioningThickness < 2.0) {
        return false; // Минимальная толщина амортизации 2 см
    }

    if (fragilityLevel > 7.0 && !requiresCushioning) {
        return false; // Высокая хрупкость требует амортизации
    }

    return true;
}

double FragileCargo::calculateRequiredCushioning() const {
    double baseCushioning = 2.0; // Базовая толщина 2 см

    if (fragilityLevel > 8.0) {
        baseCushioning += 3.0; // +3 см для очень хрупких
    }
    else if (fragilityLevel > 5.0) {
        baseCushioning += 1.5; // +1.5 см для хрупких
    }

    // Учет веса - тяжелые хрупкие предметы требуют больше амортизации
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
        surcharge = 0.4; // 40% надбавка для очень хрупких
    }
    else if (fragilityLevel > 4.0) {
        surcharge = 0.25; // 25% надбавка для хрупких
    }
    else {
        surcharge = 0.15; // 15% надбавка для слегка хрупких
    }

    // Дополнительная надбавка за специальные требования
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