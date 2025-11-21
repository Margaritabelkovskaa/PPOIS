
#ifndef TITLESEARCH_H
#define TITLESEARCH_H

#include "SearchEngine.h"

class TitleSearch : public SearchEngine {
public:
    TitleSearch(const std::shared_ptr<Catalog>& catalog);
    std::vector<std::shared_ptr<LibraryItem>> search(const std::string& query) const override;
    std::string getSearchType() const override;

private:
    bool containsIgnoreCase(const std::string& text, const std::string& searchText) const;
    std::string toLowercase(const std::string& str) const;
};

#endif
