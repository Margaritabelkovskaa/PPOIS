#include "Inventory.h"
#include "BookCopy.h"
#include "Employee.h"

Inventory::Inventory(int id, const shared_ptr<Employee>& employee, const string& startDate)
    : inventoryId(id), startDate(startDate), conductedBy(employee), status("in_progress") {
}

bool Inventory::addItem(const shared_ptr<BookCopy>& item) {
    if (!item) return false;

    // Проверяем, нет ли уже этого экземпляра
    for (const auto& existingItem : items) {
        if (existingItem && existingItem->getInventoryNumber() == item->getInventoryNumber()) {
            return false;
        }
    }

    items.push_back(item);
    return true;
}

bool Inventory::removeItem(const string& inventoryNumber) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it) && (*it)->getInventoryNumber() == inventoryNumber) {
            items.erase(it);
            return true;
        }
    }
    return false;
}

bool Inventory::containsItem(const string& inventoryNumber) const {
    for (const auto& item : items) {
        if (item && item->getInventoryNumber() == inventoryNumber) {
            return true;
        }
    }
    return false;
}

double Inventory::calculateTotalValue() const {
    double total = 0.0;
    for (const auto& item : items) {
        if (item && item->getBook()) {
            total += item->getBook()->getReplacementCost();
        }
    }
    return total;
}

int Inventory::getMissingItemsCount() const {
    int missing = 0;
    // В реальной системе здесь была бы логика сравнения с ожидаемым списком
    // Сейчас просто возвращаем 0 для демонстрации
    return missing;
}

int Inventory::getDamagedItemsCount() const {
    int damaged = 0;
    for (const auto& item : items) {
        if (item && item->needsMaintenance()) {
            damaged++;
        }
    }
    return damaged;
}

bool Inventory::isCompleted() const {
    return status == "completed";
}

string Inventory::getInventoryStatus() const {
    return "Inventory " + to_string(inventoryId) + ": " + status +
        ", Items: " + to_string(items.size()) +
        ", Damaged: " + to_string(getDamagedItemsCount());
}

vector<shared_ptr<BookCopy>> Inventory::getItemsNeedingMaintenance() const {
    vector<shared_ptr<BookCopy>> result;
    for (const auto& item : items) {
        if (item && item->needsMaintenance()) {
            result.push_back(item);
        }
    }
    return result;
}

void Inventory::markAsCompleted() {
    status = "completed";
    endDate = "2024-12-19"; // В реальной системе - текущая дата
}

void Inventory::updateStatus(const string& newStatus) {
    status = newStatus;
}

int Inventory::getInventoryId() const {
    return inventoryId;
}

string Inventory::getStartDate() const {
    return startDate;
}

string Inventory::getEndDate() const {
    return endDate;
}

string Inventory::getStatus() const {
    return status;
}

shared_ptr<Employee> Inventory::getConductedBy() const {
    return conductedBy;
}

int Inventory::getItemsCount() const {
    return items.size();
}

vector<shared_ptr<BookCopy>> Inventory::getAllItems() const {
    return items;
}