// [file name]: MaterialTypeSearch.h
#ifndef MATERIALTYPESEARCH_H
#define MATERIALTYPESEARCH_H

#include "SearchEngine.h"
#include "EBook.h"
#include "Audiobook.h"
#include "StudentBook.h"
#include "Article.h"
#include "Newspaper.h"
#include <typeinfo>

class MaterialTypeSearch : public SearchEngine {
public:
    MaterialTypeSearch(const shared_ptr<Catalog>& catalog);

    vector<shared_ptr<Book>> search(const string& query) const override;
    string getSearchType() const override;

    // Специализированные методы поиска по типу материала
    vector<shared_ptr<EBook>> searchEBooks() const;
    vector<shared_ptr<Audiobook>> searchAudiobooks() const;
    vector<shared_ptr<StudentBook>> searchStudentBooks() const;
    vector<shared_ptr<Article>> searchArticles() const;
    vector<shared_ptr<Newspaper>> searchNewspapers() const;

    template<typename T>
    vector<shared_ptr<T>> searchByType() const;
};

#endif