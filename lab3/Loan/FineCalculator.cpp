#include "FineCalculator.h"

double FineCalculator::calculateLateFine(const shared_ptr<LibraryItem>& item, int daysLate) {
    if (!item || daysLate <= 0) return 0.0;

    double dailyRate = 10.0; // базовая ставка

    // Разные ставки для разных типов
    if (dynamic_pointer_cast<Book>(item)) dailyRate = 15.0;
    if (dynamic_pointer_cast<EBook>(item)) dailyRate = 5.0;
    if (dynamic_pointer_cast<Audiobook>(item)) dailyRate = 5.0;
    if (dynamic_pointer_cast<Magazine>(item)) dailyRate = 8.0;
    if (dynamic_pointer_cast<StudentBook>(item)) dailyRate = 20.0;
    if (dynamic_pointer_cast<Article>(item)) dailyRate = 12.0;

    return daysLate * dailyRate;
}

double FineCalculator::calculateDamageFine(const shared_ptr<LibraryItem>& item, const string& damageType) {
    if (!item) return 0.0;

    double baseFine = 0.0;

    if (damageType == "minor") baseFine = 100.0;
    else if (damageType == "moderate") baseFine = 300.0;
    else if (damageType == "severe") baseFine = 500.0;
    else if (damageType == "lost") baseFine = 1000.0;
    else return 0.0;

    // Умножаем на коэффициент типа
    double multiplier = 1.0;
    if (dynamic_pointer_cast<StudentBook>(item)) multiplier = 2.0;
    if (dynamic_pointer_cast<Book>(item)) multiplier = 1.5;
    if (dynamic_pointer_cast<Article>(item)) multiplier = 1.2;
    if (dynamic_pointer_cast<Magazine>(item)) multiplier = 0.8;
    if (dynamic_pointer_cast<EBook>(item)) multiplier = 0.5;
    if (dynamic_pointer_cast<Audiobook>(item)) multiplier = 0.5;

    return baseFine * multiplier;
}