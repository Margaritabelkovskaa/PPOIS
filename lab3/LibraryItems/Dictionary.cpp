#include "Dictionary.h"

Dictionary::Dictionary(const std::string& isbn, const std::string& title,
    const std::shared_ptr<Author>& author, int publicationYear,
    const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
    const std::shared_ptr<Language>& bookLanguage,
    const std::shared_ptr<Language>& sourceLang,
    const std::shared_ptr<Language>& targetLang,
    int wordCount, double cost)
    : Book(isbn, title, author, publicationYear, genre, publisher, bookLanguage, cost),
    sourceLanguage(sourceLang), targetLanguage(targetLang), wordCount(wordCount) {
}

bool Dictionary::canBeBorrowed() const {
    return false;
}

int Dictionary::getLoanDuration() const  {
    return 0;
}

std::shared_ptr<Language> Dictionary::getSourceLanguage() const {
    return sourceLanguage;
}

std::shared_ptr<Language> Dictionary::getTargetLanguage() const {
    return targetLanguage;
}

int Dictionary::getWordCount() const {
    return wordCount;
}

bool Dictionary::isBilingual() const {
    return sourceLanguage && targetLanguage &&
        sourceLanguage->getCode() != targetLanguage->getCode();
}

bool Dictionary::isMonolingual() const {
    return sourceLanguage && targetLanguage &&
        sourceLanguage->getCode() == targetLanguage->getCode();
}