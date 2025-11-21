#ifndef AUTHORSEARCH_H
#define AUTHORSEARCH_H

#include "SearchEngine.h"

class Book;
class Article;
class StudentBook;

class AuthorSearch : public SearchEngine {
public:
    AuthorSearch(const std::shared_ptr<Catalog>& catalog);
    std::vector<std::shared_ptr<LibraryItem>> search(const std::string& query) const override;
    std::string getSearchType() const override;

private:
    bool hasMatchingAuthor(const std::shared_ptr<LibraryItem>& item,
        const std::string& lowerQuery) const;
    bool checkBookAuthor(const std::shared_ptr<Book>& book,
        const std::string& lowerQuery) const;
    bool checkArticleAuthors(const std::shared_ptr<Article>& article,
        const std::string& lowerQuery) const;
    bool checkStudentBookAuthor(const std::shared_ptr<StudentBook>& studentBook,
        const std::string& lowerQuery) const;
    std::string toLowercase(const std::string& str) const;
};

#endif