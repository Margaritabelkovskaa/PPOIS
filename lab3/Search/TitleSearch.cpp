// [file name]: TitleSearch.cpp
#include "TitleSearch.h"
#include <algorithm>

TitleSearch::TitleSearch(const shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

vector<shared_ptr<Book>> TitleSearch::search(const string& query) const {
    return searchPartial(query);
}

string TitleSearch::getSearchType() const {
    return "Title Search";
}

vector<shared_ptr<Book>> TitleSearch::searchPartial(const string& partialTitle) const {
    vector<shared_ptr<Book>> result;
    if (!catalog || partialTitle.empty()) return result;

    auto allBooks = catalog->getAllBooks();
    for (const auto& book : allBooks) {
        if (book && book->getTitle().find(partialTitle) != string::npos) {
            result.push_back(book);
        }
    }
    return result;
}

vector<shared_ptr<Book>> TitleSearch::searchExact(const string& exactTitle) const {
    vector<shared_ptr<Book>> result;
    if (!catalog || exactTitle.empty()) return result;

    auto allBooks = catalog->getAllBooks();
    for (const auto& book : allBooks) {
        if (book && book->getTitle() == exactTitle) {
            result.push_back(book);
        }
    }
    return result;
}