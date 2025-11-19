#include "EBook.h"

EBook::EBook(const std::string& isbn, const std::string& title,
    const std::shared_ptr<Author>& author, int publicationYear,
    const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
    const std::shared_ptr<Language>& bookLanguage,
    const std::string& format, double fileSize, const std::string& downloadLink, double cost)
    : Book(isbn, title, author, publicationYear, genre, publisher, bookLanguage, cost),
    format(format), fileSize(fileSize), downloadLink(downloadLink) {
}

bool EBook::canBeBorrowed() const {
    return isAvailable && canBeDownloaded();
}

int EBook::getLoanDuration() const {
    return 14;
}

bool EBook::canBeDownloaded() const {
    return !downloadLink.empty() && isSupportedFormat();
}

bool EBook::isSupportedFormat() const {
    return format == "PDF" || format == "EPUB" || format == "MOBI";
}

bool EBook::isLargeFile() const {
    return fileSize > 50.0;
}

std::string EBook::getFormat() const {
    return format;
}

double EBook::getFileSize() const {
    return fileSize;
}

std::string EBook::getDownloadLink() const {
    return downloadLink;
}