#include "Newspaper.h"

Newspaper::Newspaper(const string& title, const string& publicationDate,
    const string& edition, int pageCount)
    : LibraryItem(title.substr(0, 10), title), publicationDate(publicationDate),
    edition(edition), pageCount(pageCount) {
}

bool Newspaper::isTodayNewspaper() const {
    return publicationDate == "2024-12-19";
}

bool Newspaper::isWeekendEdition() const {
    return edition == "weekend" || edition == "sunday";
}

double Newspaper::calculateReplacementCost() const {
    return 50.0;
}

bool Newspaper::isLocalNewspaper() const {
    return title.find("Local") != string::npos || title.find("Regional") != string::npos;
}

int Newspaper::getReadingTime() const {
    return pageCount * 2;
}

string Newspaper::getPublicationDate() const {
    return publicationDate;
}

string Newspaper::getEdition() const {
    return edition;
}

int Newspaper::getPageCount() const {
    return pageCount;
}