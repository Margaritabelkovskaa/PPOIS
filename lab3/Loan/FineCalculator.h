#ifndef FINECALCULATOR_H
#define FINECALCULATOR_H

#include "LibraryItem.h"
#include <memory>

class FineCalculator {
public:
    // Процент от стоимости за день просрочки
    static const double DAILY_LATE_PERCENTAGE;
    
    // Проценты от стоимости за разные типы повреждений
    static const double MINOR_DAMAGE_PERCENTAGE;
    static const double MODERATE_DAMAGE_PERCENTAGE; 
    static const double SEVERE_DAMAGE_PERCENTAGE;
    static const double LOST_ITEM_PERCENTAGE;

    // Расчет штрафов
    static double calculateLateFine(const std::shared_ptr<LibraryItem>& item, int daysLate);
    static double calculateDamageFine(const std::shared_ptr<LibraryItem>& item, const std::string& damageType);
    static double calculateLostItemFine(const std::shared_ptr<LibraryItem>& item);
};

#endif
