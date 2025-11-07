// [file name]: GenreSearch.cpp
#include "GenreSearch.h"

GenreSearch::GenreSearch(const shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

vector<shared_ptr<Book>> GenreSearch::search(const string& query) const {
    return searchByGenreName(query);
}

string GenreSearch::getSearchType() const {
    return "Genre Search";
}

vector<shared_ptr<Book>> GenreSearch::searchByGenreName(const string& genreName) const {
    return catalog ? catalog->findBooksByGenre(genreName) : vector<shared_ptr<Book>>();
}

vector<shared_ptr<Book>> GenreSearch::searchRareGenres() const {
    vector<shared_ptr<Book>> result;
    if (!catalog) return result;

    auto allBooks = catalog->getAllBooks();
    for (const auto& book : allBooks) {
        if (book && book->getGenre() && book->getGenre()->isRareGenre()) {
            result.push_back(book);
        }
    }
    return result;
}