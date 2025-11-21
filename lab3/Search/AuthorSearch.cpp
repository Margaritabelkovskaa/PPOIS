#include "AuthorSearch.h"
#include "Catalog.h"
#include "Book.h"
#include "Article.h"
#include "StudentBook.h"
#include <algorithm>
#include <cctype>

AuthorSearch::AuthorSearch(const std::shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

std::vector<std::shared_ptr<LibraryItem>> AuthorSearch::search(const std::string& query) const {
    if (!catalog || query.empty()) return {};

    auto allItems = catalog->getAllItems();
    std::vector<std::shared_ptr<LibraryItem>> result;
    std::string lowerQuery = toLowercase(query);

    for (const auto& item : allItems) {
        if (hasMatchingAuthor(item, lowerQuery)) {
            result.push_back(item);
        }
    }

    return result;
}

bool AuthorSearch::hasMatchingAuthor(const std::shared_ptr<LibraryItem>& item,
    const std::string& lowerQuery) const {
    if (auto book = std::dynamic_pointer_cast<Book>(item)) {
        return checkBookAuthor(book, lowerQuery);
    }
    else if (auto article = std::dynamic_pointer_cast<Article>(item)) {
        return checkArticleAuthors(article, lowerQuery);
    }
    else if (auto studentBook = std::dynamic_pointer_cast<StudentBook>(item)) {
        return checkStudentBookAuthor(studentBook, lowerQuery);
    }
    return false;
}

bool AuthorSearch::checkBookAuthor(const std::shared_ptr<Book>& book,
    const std::string& lowerQuery) const {
    if (!book->getAuthor()) return false;
    std::string authorName = toLowercase(book->getAuthor()->getName());
    return authorName.find(lowerQuery) != std::string::npos;
}

bool AuthorSearch::checkArticleAuthors(const std::shared_ptr<Article>& article,
    const std::string& lowerQuery) const {
    auto authors = article->getAuthors();
    for (const auto& author : authors) {
        std::string authorName = toLowercase(author);
        if (authorName.find(lowerQuery) != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool AuthorSearch::checkStudentBookAuthor(const std::shared_ptr<StudentBook>& studentBook,
    const std::string& lowerQuery) const {
    if (!studentBook->getAuthor()) return false;
    std::string authorName = toLowercase(studentBook->getAuthor()->getName());
    return authorName.find(lowerQuery) != std::string::npos;
}

std::string AuthorSearch::toLowercase(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string AuthorSearch::getSearchType() const {
    return "Author Search";
}