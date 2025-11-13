#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"
#include "Publisher.h"   
#include <vector>
#include <memory>

using namespace std;

class Magazine : public LibraryItem {
private:
    string issn;
    int issueNumber;
    string publicationDate;
    string frequency;
    shared_ptr<Publisher> publisher;  

public:
    Magazine(const string& issn, const string& title, 
             const shared_ptr<Publisher>& publisher, int issueNumber,
             const string& publicationDate, const string& frequency = "monthly");

    bool validateISSN() const;
    bool isCurrentIssue() const;
    double calculateReplacementCost() const override;
    bool isQuarterly() const;
    int getIssueYear() const;
    
    shared_ptr<Publisher> getPublisher() const;

    string getISSN() const;
    int getIssueNumber() const;
    string getPublicationDate() const;
    string getFrequency() const;
};

#endif

