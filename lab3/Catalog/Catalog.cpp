#include "Catalog.h"
#include "Book.h"
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include "Article.h"
#include "Magazine.h"
#include "Newspaper.h"

Catalog::Catalog(const string& name) : name(name) {
}

bool Catalog::addItem(const shared_ptr<LibraryItem>& item) {
    if (!item || itemsById.count(item->getID()) > 0) {
        return false;
    }

    items.push_back(item);
    itemsById[item->getID()] = item;

    // ÈÍÄÅÊÑÀÖÈß ÄËß ÊÍÈÃ
    if (auto book = dynamic_pointer_cast<Book>(item)) {
        booksByISBN[book->getISBN()] = book;

        if (auto author = book->getAuthor()) {
            itemsByAuthor[author->getName()].push_back(item);
        }

        if (auto genre = book->getGenre()) {
            itemsByGenre[genre->getGenreName()].push_back(item);
        }

        if (auto publisher = book->getPublisher()) {
            itemsByPublisher[publisher->getName()].push_back(item);
        }
    }

    // ÈÍÄÅÊÑÀÖÈß ÄËß ÑÒÀÒÅÉ
    if (auto article = dynamic_pointer_cast<Article>(item)) {
        auto authors = article->getAuthors();
        for (const auto& author : authors) {
            itemsByAuthor[author].push_back(item);
        }
    }

    // ÈÍÄÅÊÑÀÖÈß ÄËß ÆÓĞÍÀËÎÂ/ÃÀÇÅÒ
    if (auto magazine = dynamic_pointer_cast<Magazine>(item)) {
        if (auto publisher = magazine->getPublisher()) {
            itemsByPublisher[publisher->getName()].push_back(item);
        }
    }

    if (auto newspaper = dynamic_pointer_cast<Newspaper>(item)) {
        if (auto publisher = newspaper->getPublisher()) {
            itemsByPublisher[publisher->getName()].push_back(item);
        }
    }

    return true;
}

bool Catalog::removeItem(const string& id) {
    auto itemIt = itemsById.find(id);
    if (itemIt == itemsById.end()) {
        return false;
    }

    auto item = itemIt->second;
    itemsById.erase(itemIt);

    // ÓÄÀËÅÍÈÅ ÈÇ ÎÑÍÎÂÍÎÃÎ ÂÅÊÒÎĞÀ
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            items.erase(it);
            break;
        }
    }

    // ÏÅĞÅÑÒĞÎÉÊÀ ÈÍÄÅÊÑÎÂ
    rebuildIndex();
    return true;
}

shared_ptr<LibraryItem> Catalog::findItemById(const string& id) const {
    auto it = itemsById.find(id);
    return it != itemsById.end() ? it->second : nullptr;
}

shared_ptr<Book> Catalog::findBookByISBN(const string& isbn) const {
    auto it = booksByISBN.find(isbn);
    if (it != booksByISBN.end()) {
        return dynamic_pointer_cast<Book>(it->second);
    }
    return nullptr;
}
vector<shared_ptr<LibraryItem>> Catalog::findItemsByAuthor(const string& authorName) const {
    auto it = itemsByAuthor.find(authorName);
    return it != itemsByAuthor.end() ? it->second : vector<shared_ptr<LibraryItem>>();
}

vector<shared_ptr<LibraryItem>> Catalog::findItemsByGenre(const string& genreName) const {
    auto it = itemsByGenre.find(genreName);
    return it != itemsByGenre.end() ? it->second : vector<shared_ptr<LibraryItem>>();
}

vector<shared_ptr<LibraryItem>> Catalog::findItemsByPublisher(const string& publisherName) const {
    auto it = itemsByPublisher.find(publisherName);
    return it != itemsByPublisher.end() ? it->second : vector<shared_ptr<LibraryItem>>();
}

int Catalog::getTotalItems() const {
    return items.size();
}

vector<string> Catalog::getAllGenres() const {
    vector<string> genres;
    for (const auto& pair : itemsByGenre) {
        genres.push_back(pair.first);
    }
    return genres;
}

vector<string> Catalog::getAllPublishers() const {
    vector<string> publishers;
    for (const auto& pair : itemsByPublisher) {
        publishers.push_back(pair.first);
    }
    return publishers;
}

vector<string> Catalog::getAllAuthors() const {
    vector<string> authors;
    for (const auto& pair : itemsByAuthor) {
        authors.push_back(pair.first);
    }
    return authors;
}

vector<shared_ptr<LibraryItem>> Catalog::getAllItems() const {
    return items;
}

void Catalog::rebuildIndex() {
    itemsByAuthor.clear();
    itemsByGenre.clear();
    itemsByPublisher.clear();
    booksByISBN.clear();

    for (const auto& item : items) {
        itemsById[item->getID()] = item;

        if (auto book = dynamic_pointer_cast<Book>(item)) {
            booksByISBN[book->getISBN()] = book;

            if (auto author = book->getAuthor()) {
                itemsByAuthor[author->getName()].push_back(item);
            }

            if (auto genre = book->getGenre()) {
                itemsByGenre[genre->getGenreName()].push_back(item);
            }

            if (auto publisher = book->getPublisher()) {
                itemsByPublisher[publisher->getName()].push_back(item);
            }
        }

        if (auto article = dynamic_pointer_cast<Article>(item)) {
            auto authors = article->getAuthors();
            for (const auto& author : authors) {
                itemsByAuthor[author].push_back(item);
            }
        }

        if (auto magazine = dynamic_pointer_cast<Magazine>(item)) {
            if (auto publisher = magazine->getPublisher()) {
                itemsByPublisher[publisher->getName()].push_back(item);
            }
        }

        if (auto newspaper = dynamic_pointer_cast<Newspaper>(item)) {
            if (auto publisher = newspaper->getPublisher()) {
                itemsByPublisher[publisher->getName()].push_back(item);
            }
        }
    }
}
