#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"
#include "Publisher.h"   
#include "Article.h"  

class Magazine : public LibraryItem {
private:
    string issn;
    int issueNumber;
    string publicationDate;
    string frequency;
    shared_ptr<Publisher> publisher;  
    vector<shared_ptr<Article>> articles;  

public:
    Magazine(const string& issn, const string& title, 
             const shared_ptr<Publisher>& publisher, int issueNumber,
             const string& publicationDate, const string& frequency = "monthly");

    // Существующие методы + новые
    bool validateISSN() const;
    bool isCurrentIssue() const;
    double calculateReplacementCost() const override;
    bool isQuarterly() const;
    int getIssueYear() const;
    
    void addArticle(const shared_ptr<Article>& article);
    vector<shared_ptr<Article>> getArticles() const;
    shared_ptr<Publisher> getPublisher() const;  // новый геттер
};


#endif
