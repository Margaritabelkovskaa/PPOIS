// [file name]: AuthorSearch.h
#ifndef AUTHORSEARCH_H
#define AUTHORSEARCH_H

#include "SearchEngine.h"

class AuthorSearch : public SearchEngine {
public:
    AuthorSearch(const shared_ptr<Catalog>& catalog);

    vector<shared_ptr<Book>> search(const string& query) const override;
    string getSearchType() const override;

    vector<shared_ptr<Book>> searchByAuthorName(const string& authorName) const;
    vector<shared_ptr<Book>> searchByNationality(const string& nationality) const;
};

#endif
