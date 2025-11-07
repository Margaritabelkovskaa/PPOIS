#include "LibraryItem.h"
#include <cctype>

LibraryItem::LibraryItem(const std::string& id, const std::string& title)
    : id(id), title(title), isAvailable(true) {
}

bool LibraryItem::validateID() const {
    return !id.empty() && id.length() >= 3;
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