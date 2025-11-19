#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"
#include <string>
#include <memory>

class EBook : public Book {
private:
    std::string format;
    double fileSize;
    std::string downloadLink;

public:
    EBook(const std::string& isbn, const std::string& title,
        const std::shared_ptr<Author>& author, int publicationYear,
        const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
        const std::shared_ptr<Language>& bookLanguage,
        const std::string& format, double fileSize, const std::string& downloadLink,
        double cost = 0.0);

    bool canBeBorrowed() const override;
    int getLoanDuration() const override;

    bool canBeDownloaded() const;
    bool isSupportedFormat() const;
    bool isLargeFile() const;

    std::string getFormat() const;
    double getFileSize() const;
    std::string getDownloadLink() const;
};

#endif