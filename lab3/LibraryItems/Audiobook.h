#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"
#include <string>
#include <memory>

class Audiobook : public Book {
private:
    double duration;
    std::string format;
    std::string narrator;

public:
    Audiobook(const std::string& isbn, const std::string& title,
        const std::shared_ptr<Author>& author, int publicationYear,
        const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
        const std::shared_ptr<Language>& bookLanguage,
        double duration, const std::string& format, const std::string& narrator,
        double cost = 0.0);

    bool canBeBorrowed() const override;
    int getLoanDuration() const override;

    bool isLongAudiobook() const;
    bool isSupportedFormat() const;
    std::string getDurationFormatted() const;

    double getDuration() const;
    std::string getFormat() const;
    std::string getNarrator() const;
};

#endif