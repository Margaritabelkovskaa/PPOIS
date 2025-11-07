// [file name]: GenreSearch.h
#ifndef GENRESEARCH_H
#define GENRESEARCH_H

#include "SearchEngine.h"

class GenreSearch : public SearchEngine {
public:
    GenreSearch(const shared_ptr<Catalog>& catalog);

    vector<shared_ptr<Book>> search(const string& query) const override;
    string getSearchType() const override;

    vector<shared_ptr<Book>> searchByGenreName(const string& genreName) const;
    vector<shared_ptr<Book>> searchRareGenres() const;
};

#endif

