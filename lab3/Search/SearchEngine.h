
#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <memory>
#include <vector>
#include <string>

class Catalog;
class LibraryItem;

class SearchEngine {
protected:
    std::shared_ptr<Catalog> catalog;

public:
    SearchEngine(const std::shared_ptr<Catalog>& catalog);
    virtual ~SearchEngine() = default;

    virtual std::vector<std::shared_ptr<LibraryItem>> search(const std::string& query) const = 0;
    virtual std::string getSearchType() const = 0;

    std::shared_ptr<Catalog> getCatalog() const;
};

#endif