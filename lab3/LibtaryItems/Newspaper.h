#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "LibraryItem.h"

using namespace std;

class Newspaper : public LibraryItem {
private:
    string publicationDate;
    string edition;
    int pageCount;

public:
    Newspaper(const string& title, const string& publicationDate,
        const string& edition = "daily", int pageCount = 24);

    bool isTodayNewspaper() const;
    bool isWeekendEdition() const;
    double calculateReplacementCost() const override;
    bool isLocalNewspaper() const;
    int getReadingTime() const;

    string getPublicationDate() const;
    string getEdition() const;
    int getPageCount() const;
};

#endif