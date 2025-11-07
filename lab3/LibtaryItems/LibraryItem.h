#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <memory>

class LibraryItem {
protected:
    std::string id;
    std::string title;
    bool isAvailable;

public:
    LibraryItem(const std::string& id, const std::string& title);
    virtual ~LibraryItem() = default;

    virtual bool validateID() const;
    virtual double calculateReplacementCost() const = 0;

    bool checkAvailability() const;

    void setAvailable(bool available);
    std::string getID() const;
    std::string getTitle() const;
};

#endif