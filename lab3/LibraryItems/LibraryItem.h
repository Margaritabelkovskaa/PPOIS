#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>

class LibraryItem {
protected:
    std::string id;
    std::string title;
    bool isAvailable;
    double replacementCost;

public:
    LibraryItem(const std::string& id, const std::string& title, double cost = 0.0);
    virtual ~LibraryItem() = default;

    // ¬»–“”¿À‹Õ€≈ Ã≈“Œƒ€
    virtual bool canBeBorrowed() const;
    virtual int getLoanDuration() const = 0;  // ◊»—“Œ ¬»–“”¿À‹Õ€…

    bool checkAvailability() const;
    void setAvailable(bool available);
    std::string getID() const;
    std::string getTitle() const;

    double getReplacementCost() const;
    void setReplacementCost(double cost);
};

#endif