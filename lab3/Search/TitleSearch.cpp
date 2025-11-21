#include "TitleSearch.h"
#include "Catalog.h"
#include <algorithm>
#include <cctype>

TitleSearch::TitleSearch(const std::shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

std::vector<std::shared_ptr<LibraryItem>> TitleSearch::search(const std::string& query) const {
    if (!catalog || query.empty()) return {};

    auto allItems = catalog->getAllItems();
    std::vector<std::shared_ptr<LibraryItem>> result;
    std::string lowerQuery = toLowercase(query);

    for (const auto& item : allItems) {
        if (containsIgnoreCase(item->getTitle(), lowerQuery)) {
            result.push_back(item);
        }
    }

    return result;
}

bool TitleSearch::containsIgnoreCase(const std::string& text, const std::string& searchText) const {
    std::string lowerText = toLowercase(text);
    return lowerText.find(searchText) != std::string::npos;
}

std::string TitleSearch::toLowercase(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string TitleSearch::getSearchType() const {
    return "Title Search";
}