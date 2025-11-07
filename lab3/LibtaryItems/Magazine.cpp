#include "Magazine.h"

Magazine::Magazine(const string& issn, const string& title, int issueNumber,
    const string& publicationDate, const string& frequency)
    : LibraryItem(issn, title), issn(issn), issueNumber(issueNumber),
    publicationDate(publicationDate), frequency(frequency) {
}

bool Magazine::validateISSN() const {
    return issn.length() == 8 || issn.length() == 13;
}

bool Magazine::isCurrentIssue() const {
    if (publicationDate.length() >= 4) {
        int pubYear = stoi(publicationDate.substr(0, 4));
        return pubYear == 2024;
    }
    return false;
}

double Magazine::calculateReplacementCost() const {
    return 200.0;
}

bool Magazine::isQuarterly() const {
    return frequency == "quarterly";
}

int Magazine::getIssueYear() const {
    return publicationDate.length() >= 4 ? stoi(publicationDate.substr(0, 4)) : 0;
}

string Magazine::getISSN() const {
    return issn;
}

int Magazine::getIssueNumber() const {
    return issueNumber;
}

string Magazine::getPublicationDate() const {
    return publicationDate;
}

string Magazine::getFrequency() const {
    return frequency;
}