#include "FineCalculator.h"

const double BOOK_PENALTY_RATE = 1.5;
const double ARTICLE_PENALTY_RATE = 1.2;
const double MAGAZINE_PENALTY_RATE = 0.8;
const double DEFAULT_PENALTY_RATE = 1.0;

const double MINOR_DAMAGE_RATE = 0.1;
const double SEVERE_DAMAGE_RATE = 0.5;
const double LOST_ITEM_RATE = 1.0;

double FineCalculator::calculateLateFine(const shared_ptr<LibraryItem>& item, int daysLate) {
    if (!item || daysLate <= 0) return 0.0;

    double penaltyRate = DEFAULT_PENALTY_RATE;

     if (dynamic_pointer_cast<Book>(item)) penaltyRate = BOOK_PENALTY_RATE;
    else if (dynamic_pointer_cast<Article>(item)) penaltyRate = ARTICLE_PENALTY_RATE;
    else if (dynamic_pointer_cast<Magazine>(item)) penaltyRate = MAGAZINE_PENALTY_RATE;

    return item->getReplacementCost() * penaltyRate * daysLate;
}

double FineCalculator::calculateDamageFine(const shared_ptr<LibraryItem>& item, const string& damageType) {
    if (!item) return 0.0;

    double damageRate = 0.0;

    if (damageType == "minor") damageRate = MINOR_DAMAGE_RATE;
    else if (damageType == "severe") damageRate = SEVERE_DAMAGE_RATE;
    else if (damageType == "lost") damageRate = LOST_ITEM_RATE;
    else return 0.0;

    return item->getReplacementCost() * damageRate;
}
