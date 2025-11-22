#include "SearchService.h"
#include "Catalog.h"
#include <algorithm>

SearchService::SearchService(const std::shared_ptr<Catalog>& catalog)
    : catalog(catalog) {
    titleSearch = std::make_shared<TitleSearch>(catalog);
    authorSearch = std::make_shared<AuthorSearch>(catalog);
    genreSearch = std::make_shared<GenreSearch>(catalog);
    publisherSearch = std::make_shared<PublisherSearch>(catalog);
    materialTypeSearch = std::make_shared<MaterialTypeSearch>(catalog);

    searchStrategies = {
        {"title", [this](const std::string& q) { return titleSearch->search(q); }},
        {"author", [this](const std::string& q) { return authorSearch->search(q); }},
        {"genre", [this](const std::string& q) { return genreSearch->search(q); }},
        {"publisher", [this](const std::string& q) { return publisherSearch->search(q); }},
        {"type", [this](const std::string& q) { return materialTypeSearch->search(q); }}
    };
}

std::vector<std::shared_ptr<LibraryItem>> SearchService::search(const std::string& query, const std::string& searchType) {
    if (query.empty()) return std::vector<std::shared_ptr<LibraryItem>>();

    if (searchType == "all") {
        std::vector<std::shared_ptr<LibraryItem>> allResults;
        for (const auto& strategy : searchStrategies) {
            auto results = strategy.second(query);
            allResults.insert(allResults.end(), results.begin(), results.end());
        }

        std::sort(allResults.begin(), allResults.end());
        allResults.erase(std::unique(allResults.begin(), allResults.end()), allResults.end());
        return allResults;
    }

    auto it = searchStrategies.find(searchType);
    if (it != searchStrategies.end()) {
        return it->second(query);
    }

    return std::vector<std::shared_ptr<LibraryItem>>();
}

std::vector<std::shared_ptr<LibraryItem>> SearchService::advancedSearch(
    const std::string& title, const std::string& author,
    const std::string& genre, const std::string& publisher,
    const std::string& materialType) {

    auto allItems = catalog->getAllItems();

    // Если нет критериев - возвращаем всё
    if (title.empty() && author.empty() && genre.empty() &&
        publisher.empty() && materialType.empty()) {
        return allItems;
    }

    std::vector<std::shared_ptr<LibraryItem>> result;

    // Проверяем каждый элемент на соответствие ВСЕМ указанным критериям
    for (const auto& item : allItems) {
        bool matches = true;

        // Логика И: все непустые критерии должны совпадать
        matches = matches && (title.empty() || matchesTitle(item, title));
        matches = matches && (author.empty() || matchesAuthor(item, author));
        matches = matches && (genre.empty() || matchesGenre(item, genre));
        matches = matches && (publisher.empty() || matchesPublisher(item, publisher));
        matches = matches && (materialType.empty() || matchesMaterialType(item, materialType));

        if (matches) {
            result.push_back(item);
        }
    }

    return result;
}

// Вспомогательные методы
bool SearchService::matchesTitle(const std::shared_ptr<LibraryItem>& item,
    const std::string& title) const {
    auto results = titleSearch->search(title);
    return std::find(results.begin(), results.end(), item) != results.end();
}

bool SearchService::matchesAuthor(const std::shared_ptr<LibraryItem>& item,
    const std::string& author) const {
    auto results = authorSearch->search(author);
    return std::find(results.begin(), results.end(), item) != results.end();
}

bool SearchService::matchesGenre(const std::shared_ptr<LibraryItem>& item,
    const std::string& genre) const {
    auto results = genreSearch->search(genre);
    return std::find(results.begin(), results.end(), item) != results.end();
}

bool SearchService::matchesPublisher(const std::shared_ptr<LibraryItem>& item,
    const std::string& publisher) const {
    auto results = publisherSearch->search(publisher);
    return std::find(results.begin(), results.end(), item) != results.end();
}

bool SearchService::matchesMaterialType(const std::shared_ptr<LibraryItem>& item,
    const std::string& materialType) const {
    auto results = materialTypeSearch->search(materialType);
    return std::find(results.begin(), results.end(), item) != results.end();
}
std::vector<std::string> SearchService::getAvailableSearchTypes() const {
    std::vector<std::string> types;
    for (const auto& strategy : searchStrategies) {
        types.push_back(strategy.first);
    }
    types.push_back("all");
    return types;
}

std::shared_ptr<TitleSearch> SearchService::getTitleSearch() const {
    return titleSearch;
}

std::shared_ptr<AuthorSearch> SearchService::getAuthorSearch() const {
    return authorSearch;
}

std::shared_ptr<GenreSearch> SearchService::getGenreSearch() const {
    return genreSearch;
}

std::shared_ptr<PublisherSearch> SearchService::getPublisherSearch() const {
    return publisherSearch;
}

std::shared_ptr<MaterialTypeSearch> SearchService::getMaterialTypeSearch() const {
    return materialTypeSearch;
}