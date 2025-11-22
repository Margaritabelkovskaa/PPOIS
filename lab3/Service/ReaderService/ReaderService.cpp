#include "ReaderService.h"

bool ReaderService::canBorrow(const shared_ptr<Reader>& reader,
    const vector<shared_ptr<Loan>>& activeLoans,
    const vector<shared_ptr<Fine>>& unpaidFines) {

    if (!reader || !reader->isValid()) return false;
    if (hasOverdueLoans(activeLoans)) return false;
    if (hasSeriousFines(unpaidFines)) return false;
    if (getAvailableSlots(reader, activeLoans) <= 0) return false;

    return true;
}

bool ReaderService::hasOverdueLoans(const vector<shared_ptr<Loan>>& activeLoans) {
    for (const auto& loan : activeLoans) {
        if (loan && loan->isOverdue()) {
            return true;
        }
    }
    return false;
}

int ReaderService::getAvailableSlots(const shared_ptr<Reader>& reader,
    const vector<shared_ptr<Loan>>& activeLoans) {

    int activeCount = 0;
    for (const auto& loan : activeLoans) {
        if (loan && !loan->getIsReturned()) {
            activeCount++;
        }
    }
    return reader->getMaxLoanLimit() - activeCount;
}

double ReaderService::getTotalDebt(const vector<shared_ptr<Fine>>& fines) {
    double total = 0.0;
    for (const auto& fine : fines) {
        if (fine && !fine->getIsPaid()) {
            total += fine->getAmount();
        }
    }
    return total;
}

bool ReaderService::hasSeriousFines(const vector<shared_ptr<Fine>>& fines) {
    for (const auto& fine : fines) {
        if (fine && !fine->getIsPaid() && fine->isSeriousFine()) {
            return true;
        }
    }
    return false;
}
std::shared_ptr<Reader> ReaderService::getReader(int readerId) const {
    for (const auto& reader : readers) {
        if (reader->getReaderId() == readerId) {
            return reader;
        }
    }
    return nullptr;
}

bool ReaderService::registerReader(const std::string& name, const std::string& contactInfo,
    const std::string& readerType) {
    int newId = readers.empty() ? 1 : readers.back()->getReaderId() + 1;
    auto reader = std::make_shared<Reader>(newId, name, contactInfo, readerType);
    readers.push_back(reader);
    return true;
}

std::vector<std::shared_ptr<Reader>> ReaderService::getAllReaders() const {
    return readers;
}

bool ReaderService::removeReader(int readerId) {
    for (auto it = readers.begin(); it != readers.end(); ++it) {
        if ((*it)->getReaderId() == readerId) {
            readers.erase(it);
            return true;
        }
    }
    return false;
}