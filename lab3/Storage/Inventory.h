#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class BookCopy;
class Employee;

class Inventory {
private:
    int inventoryId;
    string startDate;
    string endDate;
    string status;
    shared_ptr<Employee> conductedBy;
    vector<shared_ptr<BookCopy>> items;

public:
    Inventory(int id, const shared_ptr<Employee>& employee, const string& startDate);

    bool addItem(const shared_ptr<BookCopy>& item);
    bool removeItem(const string& inventoryNumber);
    bool containsItem(const string& inventoryNumber) const;

    double calculateTotalValue() const;
    int getMissingItemsCount() const;
    int getDamagedItemsCount() const;
    bool isCompleted() const;

    string getInventoryStatus() const;
    vector<shared_ptr<BookCopy>> getItemsNeedingMaintenance() const;

    void markAsCompleted();
    void updateStatus(const string& newStatus);

    int getInventoryId() const;
    string getStartDate() const;
    string getEndDate() const;
    string getStatus() const;
    shared_ptr<Employee> getConductedBy() const;
    int getItemsCount() const;
    vector<shared_ptr<BookCopy>> getAllItems() const;
};

#endif