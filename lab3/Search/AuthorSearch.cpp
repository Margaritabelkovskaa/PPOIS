#include "AuthorSearch.h"

AuthorSearch::AuthorSearch(const shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

vector<shared_ptr<Book>> AuthorSearch::search(const string& query) const {
    return searchByAuthorName(query);
}

string AuthorSearch::getSearchType() const {
    return "Author Search";
}

vector<shared_ptr<Book>> AuthorSearch::searchByAuthorName(const string& authorName) const {
    return catalog ? catalog->findBooksByAuthor(authorName) : vector<shared_ptr<Book>>();
}

vector<shared_ptr<Book>> AuthorSearch::searchByNationality(const string& nationality) const {
    vector<shared_ptr<Book>> result;
    if (!catalog || nationality.empty()) return result;

    auto allBooks = catalog->getAllBooks();
    for (const auto& book : allBooks) {
        if (book && book->getAuthor() &&
            book->getAuthor()->getNationality() == nationality) {
            result.push_back(book);
        }
    }
    return result;
}