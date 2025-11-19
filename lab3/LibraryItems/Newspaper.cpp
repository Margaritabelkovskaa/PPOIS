
#include "Newspaper.h"

Newspaper::Newspaper(const std::string& id, const std::string& title,
    const std::string& publicationDate,
    const std::shared_ptr<Publisher>& publisher,
    bool current, double cost)
    : LibraryItem(id, title, cost), publicationDate(publicationDate),
    publisher(publisher), isCurrent(current) {
}

bool Newspaper::canBeBorrowed() const  {
    return false;
}

int Newspaper::getLoanDuration() const  {
    return 0;
}

std::string Newspaper::getPublicationDate() const {
    return publicationDate;
}

bool Newspaper::getIsCurrent() const {
    return isCurrent;
}

std::shared_ptr<Publisher> Newspaper::getPublisher() const {
    return publisher;
}