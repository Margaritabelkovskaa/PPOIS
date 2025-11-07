
#ifndef TITLESEARCH_H
#define TITLESEARCH_H

#include "SearchEngine.h"

class TitleSearch : public SearchEngine {
public:
    TitleSearch(const shared_ptr<Catalog>& catalog);

    vector<shared_ptr<Book>> search(const string& query) const override;
    string getSearchType() const override;

    vector<shared_ptr<Book>> searchPartial(const string& partialTitle) const;
    vector<shared_ptr<Book>> searchExact(const string& exactTitle) const;
};

#endif

