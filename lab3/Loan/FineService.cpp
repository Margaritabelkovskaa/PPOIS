#include "FineService.h"

shared_ptr<Fine> FineService::createFine(const shared_ptr<Reader>& reader,
    double amount, const string& reason,
    const shared_ptr<Loan>& loan) {

    if (!reader || amount < 0) return nullptr;

    int fineId = fines.empty() ? 1 : fines.back()->getFineId() + 1;
    auto fine = make_shared<Fine>(fineId, amount, reason, reader, loan);
    fines.push_back(fine);
    return fine;
}

vector<shared_ptr<Fine>> FineService::getReaderFines(int readerId) const {
    vector<shared_ptr<Fine>> result;
    for (const auto& fine : fines) {
        if (fine && fine->getReader()->getReaderId() == readerId) {
            result.push_back(fine);
        }
    }
    return result;
}

vector<shared_ptr<Fine>> FineService::getUnpaidFines() const {
    vector<shared_ptr<Fine>> result;
    for (const auto& fine : fines) {
        if (fine && !fine->getIsPaid()) {
            result.push_back(fine);
        }
    }
    return result;
}

vector<shared_ptr<Fine>> FineService::getSeriousFines() const {
    vector<shared_ptr<Fine>> result;
    for (const auto& fine : fines) {
        if (fine && fine->isSeriousFine()) {
            result.push_back(fine);
        }
    }
    return result;
}

double FineService::calculateTotalDebt(int readerId) const {
    double total = 0.0;
    auto readerFines = getReaderFines(readerId);
    for (const auto& fine : readerFines) {
        if (!fine->getIsPaid()) {
            total += fine->getAmount();
        }
    }
    return total;
}

bool FineService::payFine(int fineId) {
    for (auto& fine : fines) {
        if (fine->getFineId() == fineId && !fine->getIsPaid()) {
            fine->markAsPaid();
            return true;
        }
    }
    return false;
}

bool FineService::waiveFine(int fineId) {
    for (auto& fine : fines) {
        if (fine->getFineId() == fineId && fine->canBeWaived()) {
            fine->markAsPaid();
            return true;
        }
    }
    return false;
}

void FineService::addFine(const shared_ptr<Fine>& fine) {
    if (fine) {
        fines.push_back(fine);
    }
}

const vector<shared_ptr<Fine>>& FineService::getAllFines() const {
    return fines;
}