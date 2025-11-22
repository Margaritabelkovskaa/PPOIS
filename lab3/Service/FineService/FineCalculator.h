#ifndef FINECALCULATOR_H
#define FINECALCULATOR_H

#include "Book.h"
#include "EBook.h"
#include "Audiobook.h"
#include "Magazine.h"
#include "StudentBook.h"
#include "Article.h"
#include <memory>

using namespace std;

class FineCalculator {
public:
    static double calculateLateFine(const shared_ptr<LibraryItem>& item, int daysLate);
    static double calculateDamageFine(const shared_ptr<LibraryItem>& item, const string& damageType);
};

#endif