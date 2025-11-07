#include "EBook.h"

EBook::EBook(const string& isbn, const string& title, const shared_ptr<Author>& author,
    int publicationYear, const shared_ptr<Genre>& genre,
    const shared_ptr<Publisher>& publisher, const string& format,
    double fileSize, const string& downloadLink)
    : Book(isbn, title, author, publicationYear, genre, publisher),
    format(format), fileSize(fileSize), downloadLink(downloadLink), drmProtected(true) {
}

bool EBook::isSupportedFormat() const {
    return format == "PDF" || format == "EPUB" || format == "MOBI";
}

double EBook::calculateDownloadTime(double speed) const {
    return speed > 0 ? fileSize / speed : 0;
}

bool EBook::canBeDownloaded() const {
    return !downloadLink.empty() && isSupportedFormat();
}

double EBook::calculateReplacementCost() const {
    return 300.0;
}

bool EBook::isLargeFile() const {
    return fileSize > 50.0;
}

string EBook::getFileSizeMB() const {
    return to_string(fileSize) + " MB";
}

string EBook::getFormat() const {
    return format;
}

double EBook::getFileSize() const {
    return fileSize;
}

string EBook::getDownloadLink() const {
    return downloadLink;
}