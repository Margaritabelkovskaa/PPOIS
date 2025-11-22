#include "SearchEngine.h"
#include "Catalog.h"

SearchEngine::SearchEngine(const std::shared_ptr<Catalog>& catalog)
    : catalog(catalog) {
}

std::shared_ptr<Catalog> SearchEngine::getCatalog() const {
    return catalog;
}