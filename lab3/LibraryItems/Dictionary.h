#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Book.h"
#include "Language.h"
#include <string>
#include <memory>

class Dictionary : public Book {
private:
    std::shared_ptr<Language> sourceLanguage;
    std::shared_ptr<Language> targetLanguage;
    int wordCount;

public:
    Dictionary(const std::string& isbn, const std::string& title,
        const std::shared_ptr<Author>& author, int publicationYear,
        const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
        const std::shared_ptr<Language>& bookLanguage,
        const std::shared_ptr<Language>& sourceLang,
        const std::shared_ptr<Language>& targetLang,
        int wordCount = 0, double cost = 0.0);

    std::shared_ptr<Language> getSourceLanguage() const;
    std::shared_ptr<Language> getTargetLanguage() const;
    int getWordCount() const;

    bool isBilingual() const;
    bool isMonolingual() const;

    // оепенопедекемхъ
    bool canBeBorrowed() const override;
    int getLoanDuration() const override;
};

#endif