#ifndef PUBLISHERSEARCH_H
#define PUBLISHERSEARCH_H

#include "SearchEngine.h"
#include <memory>
#include <vector>
#include <string>

class Book;
class Magazine;
class Newspaper;
class StudentBook;
class PublisherSearch : public SearchEngine {
public:
    PublisherSearch(const std::shared_ptr<Catalog>& catalog);
    std::vector<std::shared_ptr<LibraryItem>> search(const std::string& query) const override;
    std::string getSearchType() const override;

    // днаюбкъел щрнр лернд
    std::vector<std::shared_ptr<LibraryItem>> searchByPublisherName(const std::string& publisherName) const;

private:
    bool hasMatchingPublisher(const std::shared_ptr<LibraryItem>& item,
        const std::string& lowerQuery) const;
    bool checkBookPublisher(const std::shared_ptr<Book>& book,
        const std::string& lowerQuery) const;
    bool checkMagazinePublisher(const std::shared_ptr<Magazine>& magazine,
        const std::string& lowerQuery) const;
    bool checkNewspaperPublisher(const std::shared_ptr<Newspaper>& newspaper,
        const std::string& lowerQuery) const;
    bool checkStudentBookPublisher(const std::shared_ptr<StudentBook>& studentBook,
        const std::string& lowerQuery) const;
    std::string toLowercase(const std::string& str) const;
};

#endif