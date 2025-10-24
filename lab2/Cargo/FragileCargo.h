#ifndef FRAGILECARGO_H
#define FRAGILECARGO_H

#include "Cargo.h"
#include <string>

class FragileCargo : public Cargo {
private:
    double fragilityLevel;            // Уровень хрупкости (1-10)
    double maxAllowedGForce;          // Максимальное допустимое ускорение (g)
    std::string handlingInstructions; // Инструкции по обращению
    bool requiresCushioning;          // Требуется амортизация
    double cushioningThickness;       // Толщина амортизации (см)
    bool requiresUprightPosition;     // Требуется вертикальное положение
    std::string stackingRestrictions; // Ограничения по штабелированию
    double insuranceMultiplier;       // Множитель страховки

public:
    FragileCargo(const std::string& desc, double weight, double volume,
        const std::string& type, bool refrigeration,
        double fragilityLevel, double maxGForce,
        const std::string& instructions, bool cushioning,
        double cushionThickness, bool uprightPosition,
        const std::string& stacking, double insuranceMultiplier);

    // Специфичные методы для хрупких грузов
    double calculateFragilityFactor() const;
    bool validatePackaging() const;
    double calculateRequiredCushioning() const;
    std::string generateHandlingGuidelines() const;
    double calculateFragileSurcharge(double baseRate) const;
    bool requiresSpecialPackaging() const;
    double getInsuranceMultiplier() const;

    // Геттеры
    double getFragilityLevel() const { return fragilityLevel; }
    double getMaxAllowedGForce() const { return maxAllowedGForce; }
    bool getRequiresUprightPosition() const { return requiresUprightPosition; }
    std::string getHandlingInstructions() const { return handlingInstructions; }
};

#endif