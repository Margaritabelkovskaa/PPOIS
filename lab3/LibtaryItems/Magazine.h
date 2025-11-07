#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

using namespace std;

class Magazine : public LibraryItem {
private:
    string issn;
    int issueNumber;
    string publicationDate;
    string frequency;

public:
    Magazine(const string& issn, const string& title, int issueNumber,
        const string& publicationDate, const string& frequency = "monthly");

    bool validateISSN() const;
    bool isCurrentIssue() const;
    double calculateReplacementCost() const override;
    bool isQuarterly() const;
    int getIssueYear() const;

    string getISSN() const;
    int getIssueNumber() const;
    string getPublicationDate() const;
    string getFrequency() const;
};

#endif