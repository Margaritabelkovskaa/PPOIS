#ifndef BOOKSTORAGESYSTEM_H
#define BOOKSTORAGESYSTEM_H

#include "BookCopy.h"
#include <string>
#include <vector>
#include <memory>
#include <map>

using namespace std;

class BookLocation {
private:
    string section;
    string rack;
    string shelf;
    string position;

public:
    BookLocation(const string& section, const string& rack, const string& shelf, const string& position);

    string getFullLocation() const;
    bool isValid() const;

    string getSection() const;
    string getRack() const;
    string getShelf() const;
    string getPosition() const;
};

class Shelf {
private:
    string shelfId;
    int capacity;
    vector<shared_ptr<BookCopy>> books;

public:
    Shelf(const string& shelfId, int capacity);

    bool addBook(const shared_ptr<BookCopy>& book);
    bool removeBook(const string& inventoryNumber);
    bool containsBook(const string& inventoryNumber) const;
    bool hasSpace() const;

    vector<shared_ptr<BookCopy>> getBooks() const;
    string getShelfId() const;
    int getBookCount() const;
    int getCapacity() const;
};

class BookRack {
private:
    string rackId;
    vector<shared_ptr<Shelf>> shelves;

public:
    BookRack(const string& rackId);

    bool addShelf(const shared_ptr<Shelf>& shelf);
    shared_ptr<Shelf> getShelf(const string& shelfId) const;

    bool addBook(const shared_ptr<BookCopy>& book, const string& shelfId);
    bool removeBook(const string& inventoryNumber);

    vector<shared_ptr<BookCopy>> getAllBooks() const;
    string getRackId() const;
    vector<shared_ptr<Shelf>> getShelves() const;
};

class StorageRoom {
private:
    string roomId;
    vector<shared_ptr<BookRack>> racks;

public:
    StorageRoom(const string& roomId);

    bool addRack(const shared_ptr<BookRack>& rack);
    shared_ptr<BookRack> getRack(const string& rackId) const;

    bool addBook(const shared_ptr<BookCopy>& book, const string& rackId, const string& shelfId);
    bool removeBook(const string& inventoryNumber);
    shared_ptr<BookCopy> findBook(const string& inventoryNumber) const;

    vector<shared_ptr<BookCopy>> getAllBooks() const;
    string getRoomId() const;
    vector<shared_ptr<BookRack>> getRacks() const;
};

class BookStorageSystem {
private:
    map<string, shared_ptr<StorageRoom>> rooms;
    map<string, shared_ptr<BookLocation>> bookLocations;

public:
    BookStorageSystem();

    bool addRoom(const shared_ptr<StorageRoom>& room);
    bool assignBookLocation(const shared_ptr<BookCopy>& book, const shared_ptr<BookLocation>& location);

    shared_ptr<BookLocation> getBookLocation(const string& inventoryNumber) const;
    shared_ptr<BookCopy> findBook(const string& inventoryNumber) const;
    string getBookFullLocation(const string& inventoryNumber) const;

    bool moveBook(const string& inventoryNumber, const shared_ptr<BookLocation>& newLocation);
    bool removeBook(const string& inventoryNumber);

    vector<shared_ptr<BookCopy>> getAllBooks() const;
    int getTotalBookCount() const;
    vector<shared_ptr<StorageRoom>> getAllRooms() const;
};

#endif