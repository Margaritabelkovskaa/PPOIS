#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"
#include "Publisher.h"
#include <string>
#include <memory>

class Magazine : public LibraryItem {
private:
    int issueNumber;
    int publicationYear;
    bool isCurrentIssue;
    std::shared_ptr<Publisher> publisher;

public:
    Magazine(const std::string& id, const std::string& title,
        int issueNumber, int publicationYear,
        const std::shared_ptr<Publisher>& publisher = nullptr,
        bool currentIssue = false, double cost = 0.0);

    int getIssueNumber() const;
    int getPublicationYear() const;
    bool getIsCurrentIssue() const;
    std::shared_ptr<Publisher> getPublisher() const;

    bool canBeBorrowed() const;
    int getLoanDuration() const;
};

#endif