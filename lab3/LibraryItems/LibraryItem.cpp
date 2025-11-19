#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& id, const std::string& title, double cost)
    : id(id), title(title), isAvailable(true), replacementCost(cost) {
}

bool LibraryItem::canBeBorrowed() const {
    return isAvailable;
}

bool LibraryItem::checkAvailability() const {
    return isAvailable;
}

void LibraryItem::setAvailable(bool available) {
    isAvailable = available;
}

std::string LibraryItem::getID() const {
    return id;
}

std::string LibraryItem::getTitle() const {
    return title;
}

double LibraryItem::getReplacementCost() const {
    return replacementCost;
}

void LibraryItem::setReplacementCost(double cost) {
    replacementCost = cost;
}