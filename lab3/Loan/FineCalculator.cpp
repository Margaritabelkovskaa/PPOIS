#include "FineCalculator.h"
#include <stdexcept>

// Инициализация констант
const double FineCalculator::DAILY_LATE_PERCENTAGE = 0.01; 

const double FineCalculator::MINOR_DAMAGE_PERCENTAGE = 0.1;    
const double FineCalculator::MODERATE_DAMAGE_PERCENTAGE = 0.3;  
const double FineCalculator::SEVERE_DAMAGE_PERCENTAGE = 0.5;   
const double FineCalculator::LOST_ITEM_PERCENTAGE = 1.0;       

double FineCalculator::calculateLateFine(const std::shared_ptr<LibraryItem>& item, int daysLate) {
    if (!item || daysLate <= 0) {
        return 0.0;
    }
    
    double replacementCost = item->getReplacementCost();
    return daysLate * (replacementCost * DAILY_LATE_PERCENTAGE);
}

double FineCalculator::calculateDamageFine(const std::shared_ptr<LibraryItem>& item, const std::string& damageType) {
    if (!item) {
        return 0.0;
    }

    double replacementCost = item->getReplacementCost();
    double percentage = 0.0;

    if (damageType == "minor") {
        percentage = MINOR_DAMAGE_PERCENTAGE;
    } else if (damageType == "moderate") {
        percentage = MODERATE_DAMAGE_PERCENTAGE;
    } else if (damageType == "severe") {
        percentage = SEVERE_DAMAGE_PERCENTAGE;
    } else {
        throw std::invalid_argument("Unknown damage type: " + damageType);
    }

    return replacementCost * percentage;
}

double FineCalculator::calculateLostItemFine(const std::shared_ptr<LibraryItem>& item) {
    if (!item) {
        return 0.0;
    }
    
    return item->getReplacementCost() * LOST_ITEM_PERCENTAGE;
}
