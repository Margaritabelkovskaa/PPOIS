#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include "Author.h"
#include "Genre.h"
#include "Publisher.h"
#include "Language.h"
#include <memory>

class Book : public LibraryItem {
private:
    std::string isbn;
    std::shared_ptr<Author> author;
    int publicationYear;
    std::shared_ptr<Genre> genre;
    std::shared_ptr<Publisher> publisher;
    std::shared_ptr<Language> bookLanguage;

public:
    Book(const std::string& isbn, const std::string& title,
        const std::shared_ptr<Author>& author, int publicationYear,
        const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
        const std::shared_ptr<Language>& bookLanguage, double cost = 0.0);

    std::string getISBN() const;
    std::shared_ptr<Author> getAuthor() const;
    int getPublicationYear() const;
    std::shared_ptr<Genre> getGenre() const;
    std::shared_ptr<Publisher> getPublisher() const;
    std::shared_ptr<Language> getBookLanguage() const;

    bool isTranslation() const;
    bool matchesReaderLanguage(const std::shared_ptr<Language>& readerLanguage) const;
    bool canBeBorrowed() const override;
    int getLoanDuration() const override;
};

#endif