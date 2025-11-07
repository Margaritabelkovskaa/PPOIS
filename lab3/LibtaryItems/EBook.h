#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

using namespace std;

class EBook : public Book {
private:
    string format;
    double fileSize;
    string downloadLink;
    bool drmProtected;

public:
    EBook(const string& isbn, const string& title, const shared_ptr<Author>& author,
        int publicationYear, const shared_ptr<Genre>& genre,
        const shared_ptr<Publisher>& publisher, const string& format,
        double fileSize, const string& downloadLink);

    bool isSupportedFormat() const;
    double calculateDownloadTime(double speed) const;
    bool canBeDownloaded() const;
    double calculateReplacementCost() const override;
    bool isLargeFile() const;
    string getFileSizeMB() const;

    string getFormat() const;
    double getFileSize() const;
    string getDownloadLink() const;
};

#endif