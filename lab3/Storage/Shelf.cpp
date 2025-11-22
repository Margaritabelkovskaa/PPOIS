#include "Shelf.h"

Shelf::Shelf(const string& shelfId, int capacity)
    : shelfId(shelfId), capacity(capacity), currentBookCount(0),
      category("general"), isReserved(false), description("") {
}

bool Shelf::addBook(const shared_ptr<BookCopy>& book) {
    if (!book || !hasSpace() || containsBook(book->getInventoryNumber())) {
        return false;
    }
    books.push_back(book);
    currentBookCount++;
    return true;
}

bool Shelf::removeBook(const string& inventoryNumber) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getInventoryNumber() == inventoryNumber) {
            books.erase(it);
            currentBookCount--;
            return true;
        }
    }
    return false;
}

bool Shelf::containsBook(const string& inventoryNumber) const {
    for (const auto& book : books) {
        if (book->getInventoryNumber() == inventoryNumber) {
            return true;
        }
    }
    return false;
}

bool Shelf::hasSpace() const {
    return currentBookCount < capacity;
}

vector<shared_ptr<BookCopy>> Shelf::getBooks() const {
    return books;
}

string Shelf::getShelfId() const {
    return shelfId;
}

int Shelf::getBookCount() const {
    return currentBookCount;
}

int Shelf::getCapacity() const {
    return capacity;
}

string Shelf::getCategory() const {
    return category;
}

void Shelf::setCategory(const string& category) {
    this->category = category;
}

bool Shelf::getIsReserved() const {
    return isReserved;
}

void Shelf::setIsReserved(bool reserved) {
    isReserved = reserved;
}

string Shelf::getDescription() const {
    return description;
}

void Shelf::setDescription(const string& desc) {
    description = desc;
}

int Shelf::getCurrentBookCount() const {
    return currentBookCount;
}
