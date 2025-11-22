#include "BookRack.h"

BookRack::BookRack(const string& rackId)
    : rackId(rackId), maxShelves(10), rackType("standard"),
      location(""), isAccessible(true) {
}

bool BookRack::addShelf(const shared_ptr<Shelf>& shelf) {
    if (!shelf || shelves.size() >= maxShelves) return false;
    shelves.push_back(shelf);
    return true;
}

shared_ptr<Shelf> BookRack::getShelf(const string& shelfId) const {
    for (const auto& shelf : shelves) {
        if (shelf->getShelfId() == shelfId) {
            return shelf;
        }
    }
    return nullptr;
}

bool BookRack::addBook(const shared_ptr<BookCopy>& book, const string& shelfId) {
    auto shelf = getShelf(shelfId);
    return shelf ? shelf->addBook(book) : false;
}

bool BookRack::removeBook(const string& inventoryNumber) {
    for (const auto& shelf : shelves) {
        if (shelf->removeBook(inventoryNumber)) {
            return true;
        }
    }
    return false;
}

vector<shared_ptr<BookCopy>> BookRack::getAllBooks() const {
    vector<shared_ptr<BookCopy>> allBooks;
    for (const auto& shelf : shelves) {
        auto shelfBooks = shelf->getBooks();
        allBooks.insert(allBooks.end(), shelfBooks.begin(), shelfBooks.end());
    }
    return allBooks;
}

string BookRack::getRackId() const {
    return rackId;
}

vector<shared_ptr<Shelf>> BookRack::getShelves() const {
    return shelves;
}

int BookRack::getMaxShelves() const {
    return maxShelves;
}

void BookRack::setMaxShelves(int max) {
    maxShelves = max;
}

string BookRack::getRackType() const {
    return rackType;
}

void BookRack::setRackType(const string& type) {
    rackType = type;
}

string BookRack::getLocation() const {
    return location;
}

void BookRack::setLocation(const string& loc) {
    location = loc;
}

bool BookRack::getIsAccessible() const {
    return isAccessible;
}

void BookRack::setIsAccessible(bool accessible) {
    isAccessible = accessible;
}

int BookRack::getTotalBooksInRack() const {
    int total = 0;
    for (const auto& shelf : shelves) {
        total += shelf->getBookCount();
    }
    return total;
}
