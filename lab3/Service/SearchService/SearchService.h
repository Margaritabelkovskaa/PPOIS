
#ifndef SEARCHSERVICE_H
#define SEARCHSERVICE_H

#include "TitleSearch.h"
#include "AuthorSearch.h"
#include "GenreSearch.h"
#include "PublisherSearch.h"  // Добавлен
#include "MaterialTypeSearch.h"
#include <map>
#include <functional>
#include <algorithm>
#include <memory>  // Добавлен
#include <vector>  // Добавлен
#include <string>  // Добавлен

class SearchService {
private:
    std::shared_ptr<Catalog> catalog; 
    std::shared_ptr<TitleSearch> titleSearch;
    std::shared_ptr<AuthorSearch> authorSearch;
    std::shared_ptr<GenreSearch> genreSearch;
    std::shared_ptr<PublisherSearch> publisherSearch;  
    std::shared_ptr<MaterialTypeSearch> materialTypeSearch;

    std::map<std::string, std::function<std::vector<std::shared_ptr<LibraryItem>>(const std::string&)>> searchStrategies;

public:
    SearchService(const std::shared_ptr<Catalog>& catalog);

    std::vector<std::shared_ptr<LibraryItem>> search(const std::string& query, const std::string& searchType = "all");
    std::vector<std::shared_ptr<LibraryItem>> advancedSearch(const std::string& title, const std::string& author,
        const std::string& genre, const std::string& publisher, const std::string& materialType);

    std::vector<std::string> getAvailableSearchTypes() const;

    std::shared_ptr<TitleSearch> getTitleSearch() const;
    std::shared_ptr<AuthorSearch> getAuthorSearch() const;
    std::shared_ptr<GenreSearch> getGenreSearch() const;
    std::shared_ptr<PublisherSearch> getPublisherSearch() const;  
    std::shared_ptr<MaterialTypeSearch> getMaterialTypeSearch() const;
    bool matchesTitle(const std::shared_ptr<LibraryItem>& item, const std::string& title) const;
    bool matchesAuthor(const std::shared_ptr<LibraryItem>& item, const std::string& author) const;
    bool matchesGenre(const std::shared_ptr<LibraryItem>& item, const std::string& genre) const;
    bool matchesPublisher(const std::shared_ptr<LibraryItem>& item, const std::string& publisher) const;
    bool matchesMaterialType(const std::shared_ptr<LibraryItem>& item, const std::string& materialType) const;
};

#endif