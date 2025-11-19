#include "Magazine.h"

Magazine::Magazine(const std::string& id, const std::string& title,
    int issueNumber, int publicationYear,
    const std::shared_ptr<Publisher>& publisher,
    bool currentIssue, double cost)
    : LibraryItem(id, title, cost), issueNumber(issueNumber),
    publicationYear(publicationYear), publisher(publisher),
    isCurrentIssue(currentIssue) {
}

int Magazine::getIssueNumber() const {
    return issueNumber;
}

int Magazine::getPublicationYear() const {
    return publicationYear;
}

bool Magazine::getIsCurrentIssue() const {
    return isCurrentIssue;
}

std::shared_ptr<Publisher> Magazine::getPublisher() const {
    return publisher;
}

bool Magazine::canBeBorrowed() const {
    return isAvailable && !isCurrentIssue;
}

int Magazine::getLoanDuration() const  {
    return 14;
}