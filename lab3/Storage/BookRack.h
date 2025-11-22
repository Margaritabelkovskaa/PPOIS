#ifndef BOOKRACK_H
#define BOOKRACK_H

#include "Shelf.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class BookRack {
private:
    string rackId;
    vector<shared_ptr<Shelf>> shelves;
    int maxShelves;           // Максимальное количество полок
    string rackType;          // Тип стеллажа
    string location;          // Расположение стеллажа в комнате
    bool isAccessible;        // Доступен ли стеллаж

public:
    BookRack(const string& rackId);

    bool addShelf(const shared_ptr<Shelf>& shelf);
    shared_ptr<Shelf> getShelf(const string& shelfId) const;

    bool addBook(const shared_ptr<BookCopy>& book, const string& shelfId);
    bool removeBook(const string& inventoryNumber);

    vector<shared_ptr<BookCopy>> getAllBooks() const;
    string getRackId() const;
    vector<shared_ptr<Shelf>> getShelves() const;
    
    // Новые методы
    int getMaxShelves() const;
    void setMaxShelves(int max);
    string getRackType() const;
    void setRackType(const string& type);
    string getLocation() const;
    void setLocation(const string& loc);
    bool getIsAccessible() const;
    void setIsAccessible(bool accessible);
    int getTotalBooksInRack() const;
};

#endif
