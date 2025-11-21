#include "PublisherSearch.h"
#include "Catalog.h"
#include "Book.h"
#include "Magazine.h"
#include "Newspaper.h"
#include "StudentBook.h"
#include <algorithm>
#include <cctype>

PublisherSearch::PublisherSearch(const std::shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

std::vector<std::shared_ptr<LibraryItem>> PublisherSearch::search(const std::string& query) const {
    if (!catalog || query.empty()) return {};

    auto allItems = catalog->getAllItems();
    std::vector<std::shared_ptr<LibraryItem>> result;
    std::string lowerQuery = toLowercase(query);

    for (const auto& item : allItems) {
        if (hasMatchingPublisher(item, lowerQuery)) {
            result.push_back(item);
        }
    }

    return result;
}

std::vector<std::shared_ptr<LibraryItem>> PublisherSearch::searchByPublisherName(const std::string& publisherName) const {
    return search(publisherName);
}

bool PublisherSearch::hasMatchingPublisher(const std::shared_ptr<LibraryItem>& item,
    const std::string& lowerQuery) const {
    if (auto book = std::dynamic_pointer_cast<Book>(item)) {
        return checkBookPublisher(book, lowerQuery);
    }
    else if (auto magazine = std::dynamic_pointer_cast<Magazine>(item)) {
        return checkMagazinePublisher(magazine, lowerQuery);
    }
    else if (auto newspaper = std::dynamic_pointer_cast<Newspaper>(item)) {
        return checkNewspaperPublisher(newspaper, lowerQuery);
    }
    else if (auto studentBook = std::dynamic_pointer_cast<StudentBook>(item)) {
        return checkStudentBookPublisher(studentBook, lowerQuery);
    }
    return false;
}

bool PublisherSearch::checkBookPublisher(const std::shared_ptr<Book>& book,
    const std::string& lowerQuery) const {
    if (!book->getPublisher()) return false;
    std::string publisherName = toLowercase(book->getPublisher()->getName());
    return publisherName.find(lowerQuery) != std::string::npos;
}

bool PublisherSearch::checkMagazinePublisher(const std::shared_ptr<Magazine>& magazine,
    const std::string& lowerQuery) const {
    if (!magazine->getPublisher()) return false;
    std::string publisherName = toLowercase(magazine->getPublisher()->getName());
    return publisherName.find(lowerQuery) != std::string::npos;
}

bool PublisherSearch::checkNewspaperPublisher(const std::shared_ptr<Newspaper>& newspaper,
    const std::string& lowerQuery) const {
    if (!newspaper->getPublisher()) return false;
    std::string publisherName = toLowercase(newspaper->getPublisher()->getName());
    return publisherName.find(lowerQuery) != std::string::npos;
}

bool PublisherSearch::checkStudentBookPublisher(const std::shared_ptr<StudentBook>& studentBook,
    const std::string& lowerQuery) const {
    if (!studentBook->getPublisher()) return false;
    std::string publisherName = toLowercase(studentBook->getPublisher()->getName());
    return publisherName.find(lowerQuery) != std::string::npos;
}

std::string PublisherSearch::toLowercase(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string PublisherSearch::getSearchType() const {
    return "Publisher Search";
}
