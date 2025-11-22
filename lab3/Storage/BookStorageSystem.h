#ifndef BOOKSTORAGESYSTEM_H
#define BOOKSTORAGESYSTEM_H

#include "StorageRoom.h"
#include "BookLocation.h"
#include <string>
#include <vector>
#include <memory>
#include <map>

using namespace std;

class BookStorageSystem {
private:
    map<string, shared_ptr<StorageRoom>> rooms;
    map<string, shared_ptr<BookLocation>> bookLocations;
    string systemName;                    // Название системы
    string version;                       // Версия системы
    int totalBooksInSystem;               // Общее количество книг в системе
    map<string, int> categoryStatistics;  // Статистика по категориям
    string adminContact;                  // Контакт администратора
    bool isSystemActive;                  // Активна ли система

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
    
    // Новые методы
    string getSystemName() const;
    void setSystemName(const string& name);
    string getVersion() const;
    void setVersion(const string& version);
    string getAdminContact() const;
    void setAdminContact(const string& contact);
    bool getIsSystemActive() const;
    void setIsSystemActive(bool active);
    map<string, int> getCategoryStatistics() const;
    void updateCategoryStatistics();
    int getRoomCount() const;
    bool hasRoom(const string& roomId) const;
    void deactivateSystem();
};

#endif
