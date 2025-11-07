#include "Book.h"
#include <chrono>

Book::Book(const string& isbn, const string& title, const shared_ptr<Author>& author,
    int publicationYear, const shared_ptr<Genre>& genre, const shared_ptr<Publisher>& publisher)
    : LibraryItem(isbn, title), isbn(isbn), author(author), publicationYear(publicationYear),
    genre(genre), publisher(publisher), replacementCost(0.0) {
}

bool Book::validateISBN(const string& isbn) {
    return isbn.length() == 13 || isbn.length() == 10;
}

double Book::calculateReplacementCost() const {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm time_info;
    localtime_s(&time_info, &now_time);
    int currentYear = time_info.tm_year + 1900;
    int age = currentYear - publicationYear;

    double baseCost = 500.0;
    if (age < 5) {
        return baseCost;
    }
    else if (age < 20) {
        return baseCost * 1.5;
    }
    else {
        return baseCost * 2.0;
    }
}

bool Book::isAntique() const {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm time_info;
    localtime_s(&time_info, &now_time);
    int currentYear = time_info.tm_year + 1900;
    return (currentYear - publicationYear) >= 50;
}

bool Book::isBestseller() const {
    return tags.size() > 5;
}

int Book::calculateBookAge() const {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm time_info;
    localtime_s(&time_info, &now_time);
    int currentYear = time_info.tm_year + 1900;
    return currentYear - publicationYear;
}

void Book::addTag(const string& tag) {
    tags.push_back(tag);
}

void Book::setReplacementCost(double cost) {
    replacementCost = cost;
}

string Book::getISBN() const {
    return isbn;
}

shared_ptr<Author> Book::getAuthor() const {
    return author;
}

int Book::getPublicationYear() const {
    return publicationYear;
}

shared_ptr<Genre> Book::getGenre() const {
    return genre;
}