#include "BookStorageSystem.h"

BookStorageSystem::BookStorageSystem()
    : systemName("Book Storage System"), version("1.0"),
      totalBooksInSystem(0), adminContact("admin@library.com"),
      isSystemActive(true) {
}

bool BookStorageSystem::addRoom(const shared_ptr<StorageRoom>& room) {
    if (!room || !isSystemActive) return false;
    rooms[room->getRoomId()] = room;
    return true;
}

bool BookStorageSystem::assignBookLocation(const shared_ptr<BookCopy>& book, const shared_ptr<BookLocation>& location) {
    if (!book || !location || !location->isValid() || !isSystemActive) return false;

    string roomId = location->getSection() + "_room";
    auto roomIt = rooms.find(roomId);
    if (roomIt == rooms.end()) return false;

    if (roomIt->second->addBook(book, location->getRack(), location->getShelf())) {
        bookLocations[book->getInventoryNumber()] = location;
        totalBooksInSystem++;
        updateCategoryStatistics();
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
            totalBooksInSystem--;
            updateCategoryStatistics();
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
    return totalBooksInSystem;
}

vector<shared_ptr<StorageRoom>> BookStorageSystem::getAllRooms() const {
    vector<shared_ptr<StorageRoom>> allRooms;
    for (const auto& roomPair : rooms) {
        allRooms.push_back(roomPair.second);
    }
    return allRooms;
}

string BookStorageSystem::getSystemName() const {
    return systemName;
}

void BookStorageSystem::setSystemName(const string& name) {
    systemName = name;
}

string BookStorageSystem::getVersion() const {
    return version;
}

void BookStorageSystem::setVersion(const string& ver) {
    version = ver;
}

string BookStorageSystem::getAdminContact() const {
    return adminContact;
}

void BookStorageSystem::setAdminContact(const string& contact) {
    adminContact = contact;
}

bool BookStorageSystem::getIsSystemActive() const {
    return isSystemActive;
}

void BookStorageSystem::setIsSystemActive(bool active) {
    isSystemActive = active;
}

map<string, int> BookStorageSystem::getCategoryStatistics() const {
    return categoryStatistics;
}

void BookStorageSystem::updateCategoryStatistics() {
    categoryStatistics.clear();
    auto allBooks = getAllBooks();
    for (const auto& book : allBooks) {
        // Здесь можно добавить логику для категоризации книг
        string category = "general"; // Временная заглушка
        categoryStatistics[category]++;
    }
}

int BookStorageSystem::getRoomCount() const {
    return rooms.size();
}

bool BookStorageSystem::hasRoom(const string& roomId) const {
    return rooms.find(roomId) != rooms.end();
}

void BookStorageSystem::deactivateSystem() {
    isSystemActive = false;
}
