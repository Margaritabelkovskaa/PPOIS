#ifndef GENRESEARCH_H
#define GENRESEARCH_H

#include "SearchEngine.h"

class Book;
class StudentBook;

class GenreSearch : public SearchEngine {
public:
    GenreSearch(const std::shared_ptr<Catalog>& catalog);
    std::vector<std::shared_ptr<LibraryItem>> search(const std::string& query) const override;
    std::string getSearchType() const override;

private:
    bool hasMatchingGenre(const std::shared_ptr<LibraryItem>& item,
        const std::string& lowerQuery) const;
    bool checkBookGenre(const std::shared_ptr<Book>& book,
        const std::string& lowerQuery) const;
    bool checkStudentBookGenre(const std::shared_ptr<StudentBook>& studentBook,
        const std::string& lowerQuery) const;
    std::string toLowercase(const std::string& str) const;
};

#endif