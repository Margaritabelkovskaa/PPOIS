#ifndef SHELF_H
#define SHELF_H

#include "BookCopy.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Shelf {
private:
    string shelfId;
    int capacity;
    int currentBookCount;
    vector<shared_ptr<BookCopy>> books;
    string category;          // Категория книг на этой полке
    bool isReserved;          // Зарезервирована ли полка
    string description;       // Описание полки

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
    
    // Новые методы
    string getCategory() const;
    void setCategory(const string& category);
    bool getIsReserved() const;
    void setIsReserved(bool reserved);
    string getDescription() const;
    void setDescription(const string& desc);
    int getCurrentBookCount() const;
};

#endif
