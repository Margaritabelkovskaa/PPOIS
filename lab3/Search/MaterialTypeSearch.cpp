
#include "MaterialTypeSearch.h"
#include "Catalog.h"

MaterialTypeSearch::MaterialTypeSearch(const std::shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

std::vector<std::shared_ptr<LibraryItem>> MaterialTypeSearch::search(const std::string& query) const {
    if (!catalog || query.empty()) return {};

    auto allItems = catalog->getAllItems();
    std::vector<std::shared_ptr<LibraryItem>> result;

    for (const auto& item : allItems) {
        if (item->getMaterialType() == query) {
            result.push_back(item);
        }
    }

    return result;
}

std::string MaterialTypeSearch::getSearchType() const {
    return "Material Type Search";
}