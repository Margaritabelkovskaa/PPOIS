#ifndef CATALOG_H
#define CATALOG_H

#include <string>
#include <vector>
#include <memory>
#include <map>

using namespace std;

class Book;
class Author;
class Genre;
class Publisher;
class LibraryItem;

class Catalog {
private:
    string name;
    vector<shared_ptr<LibraryItem>> items;

    // »Õƒ≈ —€ ƒÀﬂ ¡€—“–Œ√Œ œŒ»— ¿
    map<string, shared_ptr<LibraryItem>> itemsById;
    map<string, vector<shared_ptr<LibraryItem>>> itemsByAuthor;
    map<string, vector<shared_ptr<LibraryItem>>> itemsByGenre;
    map<string, vector<shared_ptr<LibraryItem>>> itemsByPublisher;
    map<string, shared_ptr<LibraryItem>> booksByISBN;

public:
    Catalog(const string& name);

    // Œ—ÕŒ¬Õ€≈ Œœ≈–¿÷»»
    bool addItem(const shared_ptr<LibraryItem>& item);
    bool removeItem(const string& id);

    // œŒ»—  œŒ –¿«Õ€Ã  –»“≈–»ﬂÃ
    shared_ptr<LibraryItem> findItemById(const string& id) const;
    shared_ptr<Book> findBookByISBN(const string& isbn) const;
    vector<shared_ptr<LibraryItem>> findItemsByAuthor(const string& authorName) const;
    vector<shared_ptr<LibraryItem>> findItemsByGenre(const string& genreName) const;
    vector<shared_ptr<LibraryItem>> findItemsByPublisher(const string& publisherName) const;

    // »Õ‘Œ–Ã¿÷»ﬂ Œ  ¿“¿ÀŒ√≈
    int getTotalItems() const;
    vector<string> getAllGenres() const;
    vector<string> getAllPublishers() const;
    vector<string> getAllAuthors() const;

    // ¬—≈ ›À≈Ã≈Õ“€
    vector<shared_ptr<LibraryItem>> getAllItems() const;

private:
    void rebuildIndex();
};

#endif