#ifndef MATERIALTYPESEARCH_H
#define MATERIALTYPESEARCH_H

#include "SearchEngine.h"

class MaterialTypeSearch : public SearchEngine {
public:
    MaterialTypeSearch(const std::shared_ptr<Catalog>& catalog);
    std::vector<std::shared_ptr<LibraryItem>> search(const std::string& query) const override;
    std::string getSearchType() const override;
};

#endif