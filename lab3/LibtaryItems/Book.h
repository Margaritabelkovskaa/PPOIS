#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"

using namespace std;

class Book : public LibraryItem {
private:
    string isbn;
    shared_ptr<Author> author;
    int publicationYear;
    shared_ptr<Genre> genre;
    shared_ptr<Publisher> publisher;
    vector<string> tags;
    double replacementCost;

public:
    Book(const string& isbn, const string& title, const shared_ptr<Author>& author,
        int publicationYear, const shared_ptr<Genre>& genre, const shared_ptr<Publisher>& publisher);

    static bool validateISBN(const string& isbn);
    double calculateReplacementCost() const override;
    bool isAntique() const;
    bool isBestseller() const;
    int calculateBookAge() const;

    void addTag(const string& tag);
    void setReplacementCost(double cost);

    string getISBN() const;
    shared_ptr<Author> getAuthor() const;
    int getPublicationYear() const;
    shared_ptr<Genre> getGenre() const;
};

#endif