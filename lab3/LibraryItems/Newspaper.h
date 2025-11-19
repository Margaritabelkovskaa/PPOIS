#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "LibraryItem.h"
#include "Publisher.h"
#include <string>
#include <memory>

class Newspaper : public LibraryItem {
private:
    std::string publicationDate;
    bool isCurrent;
    std::shared_ptr<Publisher> publisher;

public:
    Newspaper(const std::string& id, const std::string& title,
        const std::string& publicationDate,
        const std::shared_ptr<Publisher>& publisher = nullptr,
        bool current = false, double cost = 0.0);

    std::string getPublicationDate() const;
    bool getIsCurrent() const;
    std::shared_ptr<Publisher> getPublisher() const;

    // оепенопедекемхъ
    bool canBeBorrowed() const override;
    int getLoanDuration() const override;
};

#endif