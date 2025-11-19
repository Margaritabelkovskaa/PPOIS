#include "Book.h"

Book::Book(const std::string& isbn, const std::string& title,
    const std::shared_ptr<Author>& author, int publicationYear,
    const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
    const std::shared_ptr<Language>& bookLanguage, double cost)
    : LibraryItem(isbn, title, cost),
    isbn(isbn), author(author), publicationYear(publicationYear),
    genre(genre), publisher(publisher), bookLanguage(bookLanguage) {
}

std::string Book::getISBN() const { return isbn; }
std::shared_ptr<Author> Book::getAuthor() const { return author; }
int Book::getPublicationYear() const { return publicationYear; }
std::shared_ptr<Genre> Book::getGenre() const { return genre; }
std::shared_ptr<Publisher> Book::getPublisher() const { return publisher; }
std::shared_ptr<Language> Book::getBookLanguage() const { return bookLanguage; }

bool Book::isTranslation() const {
    if (!author || !bookLanguage) return false;
    return author->getNativeLanguage() &&
        author->getNativeLanguage()->getCode() != bookLanguage->getCode();
}

bool Book::matchesReaderLanguage(const std::shared_ptr<Language>& readerLanguage) const {
    if (!readerLanguage || !bookLanguage) return true;
    return bookLanguage->getCode() == readerLanguage->getCode();
}

bool Book::canBeBorrowed() const {
    return isAvailable;
}

int Book::getLoanDuration() const {
    return 30;
}