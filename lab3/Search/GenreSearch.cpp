#include "GenreSearch.h"
#include "Catalog.h"
#include "Book.h"
#include "StudentBook.h"
#include <algorithm>
#include <cctype>

GenreSearch::GenreSearch(const std::shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

std::vector<std::shared_ptr<LibraryItem>> GenreSearch::search(const std::string& query) const {
    if (!catalog || query.empty()) return {};

    auto allItems = catalog->getAllItems();
    std::vector<std::shared_ptr<LibraryItem>> result;
    std::string lowerQuery = toLowercase(query);

    for (const auto& item : allItems) {
        if (hasMatchingGenre(item, lowerQuery)) {
            result.push_back(item);
        }
    }

    return result;
}

bool GenreSearch::hasMatchingGenre(const std::shared_ptr<LibraryItem>& item,
    const std::string& lowerQuery) const {
    if (auto book = std::dynamic_pointer_cast<Book>(item)) {
        return checkBookGenre(book, lowerQuery);
    }
    else if (auto studentBook = std::dynamic_pointer_cast<StudentBook>(item)) {
        return checkStudentBookGenre(studentBook, lowerQuery);
    }
    return false;
}

bool GenreSearch::checkBookGenre(const std::shared_ptr<Book>& book,
    const std::string& lowerQuery) const {
    if (!book->getGenre()) return false;
    std::string genreName = toLowercase(book->getGenre()->getGenreName());
    return genreName.find(lowerQuery) != std::string::npos;
}

bool GenreSearch::checkStudentBookGenre(const std::shared_ptr<StudentBook>& studentBook,
    const std::string& lowerQuery) const {
    if (!studentBook->getGenre()) return false;
    std::string genreName = toLowercase(studentBook->getGenre()->getGenreName());
    return genreName.find(lowerQuery) != std::string::npos;
}

std::string GenreSearch::toLowercase(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string GenreSearch::getSearchType() const {
    return "Genre Search";
}