#include "BookStorageSystem.h"

// BookLocation
BookLocation::BookLocation(const string& section, const string& rack, const string& shelf, const string& position)
    : section(section), rack(rack), shelf(shelf), position(position) {
}

string BookLocation::getFullLocation() const {
    return section + " -> " + rack + " -> " + shelf + " -> " + position;
}

bool BookLocation::isValid() const {
    return !section.empty() && !rack.empty() && !shelf.empty() && !position.empty();
}

string BookLocation::getSection() const { return section; }
string BookLocation::getRack() const { return rack; }
string BookLocation::getShelf() const { return shelf; }
string BookLocation::getPosition() const { return position; }

// Shelf
Shelf::Shelf(const string& shelfId, int capacity)
    : shelfId(shelfId), capacity(capacity) {
}

bool Shelf::addBook(const shared_ptr<BookCopy>& book) {
    if (!book || !hasSpace() || containsBook(book->getInventoryNumber())) {
        return false;
    }
    books.push_back(book);
    return true;
}

bool Shelf::removeBook(const string& inventoryNumber) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getInventoryNumber() == inventoryNumber) {
            books.erase(it);
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
    return books.size() < capacity;
}

vector<shared_ptr<BookCopy>> Shelf::getBooks() const {
    return books;
}

string Shelf::getShelfId() const {
    return shelfId;
}

int Shelf::getBookCount() const {
    return books.size();
}

int Shelf::getCapacity() const {
    return capacity;
}

// BookRack
BookRack::BookRack(const string& rackId)
    : rackId(rackId) {
}

bool BookRack::addShelf(const shared_ptr<Shelf>& shelf) {
    if (!shelf) return false;
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

// StorageRoom
StorageRoom::StorageRoom(const string& roomId)
    : roomId(roomId) {
}

bool StorageRoom::addRack(const shared_ptr<BookRack>& rack) {
    if (!rack) return false;
    racks.push_back(rack);
    return true;
}

shared_ptr<BookRack> StorageRoom::getRack(const string& rackId) const {
    for (const auto& rack : racks) {
        if (rack->getRackId() == rackId) {
            return rack;
        }
    }
    return nullptr;
}

bool StorageRoom::addBook(const shared_ptr<BookCopy>& book, const string& rackId, const string& shelfId) {
    auto rack = getRack(rackId);
    return rack ? rack->addBook(book, shelfId) : false;
}

bool StorageRoom::removeBook(const string& inventoryNumber) {
    for (const auto& rack : racks) {
        if (rack->removeBook(inventoryNumber)) {
            return true;
        }
    }
    return false;
}

shared_ptr<BookCopy> StorageRoom::findBook(const string& inventoryNumber) const {
    for (const auto& rack : racks) {
        auto books = rack->getAllBooks();
        for (const auto& book : books) {
            if (book->getInventoryNumber() == inventoryNumber) {
                return book;
            }
        }
    }
    return nullptr;
}

vector<shared_ptr<BookCopy>> StorageRoom::getAllBooks() const {
    vector<shared_ptr<BookCopy>> allBooks;
    for (const auto& rack : racks) {
        auto rackBooks = rack->getAllBooks();
        allBooks.insert(allBooks.end(), rackBooks.begin(), rackBooks.end());
    }
    return allBooks;
}

string StorageRoom::getRoomId() const {
    return roomId;
}

vector<shared_ptr<BookRack>> StorageRoom::getRacks() const {
    return racks;
}

// BookStorageSystem
BookStorageSystem::BookStorageSystem() {}

bool BookStorageSystem::addRoom(const shared_ptr<StorageRoom>& room) {
    if (!room) return false;
    rooms[room->getRoomId()] = room;
    return true;
}

bool BookStorageSystem::assignBookLocation(const shared_ptr<BookCopy>& book, const shared_ptr<BookLocation>& location) {
    if (!book || !location || !location->isValid()) return false;

    string roomId = location->getSection() + "_room";
    auto roomIt = rooms.find(roomId);
    if (roomIt == rooms.end()) return false;

    if (roomIt->second->addBook(book, location->getRack(), location->getShelf())) {
        bookLocations[book->getInventoryNumber()] = location;
        return true;
    }

    return false;
}

shared_ptr<BookLocation> BookStorageSystem::getBookLocation(const string& inventoryNumber) const {
    auto it = bookLocations.find(inventoryNumber);
    return it != bookLocations.end() ? it->second : nullptr;
}

shared_ptr<BookCopy> BookStorageSystem::findBook(const string& inventoryNumber) const {
    for (const auto& roomPair : rooms) {
        auto book = roomPair.second->findBook(inventoryNumber);
        if (book) return book;
    }
    return nullptr;
}

string BookStorageSystem::getBookFullLocation(const string& inventoryNumber) const {
    auto location = getBookLocation(inventoryNumber);
    return location ? location->getFullLocation() : "Location not found";
}

bool BookStorageSystem::moveBook(const string& inventoryNumber, const shared_ptr<BookLocation>& newLocation) {
    if (!removeBook(inventoryNumber)) return false;

    auto book = findBook(inventoryNumber);
    if (!book) return false;

    return assignBookLocation(book, newLocation);
}

bool BookStorageSystem::removeBook(const string& inventoryNumber) {
    for (auto& roomPair : rooms) {
        if (roomPair.second->removeBook(inventoryNumber)) {
            bookLocations.erase(inventoryNumber);
            return true;
        }
    }
    return false;
}

vector<shared_ptr<BookCopy>> BookStorageSystem::getAllBooks() const {
    vector<shared_ptr<BookCopy>> allBooks;
    for (const auto& roomPair : rooms) {
        auto roomBooks = roomPair.second->getAllBooks();
        allBooks.insert(allBooks.end(), roomBooks.begin(), roomBooks.end());
    }
    return allBooks;
}

int BookStorageSystem::getTotalBookCount() const {
    int total = 0;
    for (const auto& roomPair : rooms) {
        total += roomPair.second->getAllBooks().size();
    }
    return total;
}

vector<shared_ptr<StorageRoom>> BookStorageSystem::getAllRooms() const {
    vector<shared_ptr<StorageRoom>> allRooms;
    for (const auto& roomPair : rooms) {
        allRooms.push_back(roomPair.second);
    }
    return allRooms;
}