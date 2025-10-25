#ifndef COMPANYFINANCE_H
#define COMPANYFINANCE_H

#include <vector>
#include <string>

class ExpenseTracker {
private:
    double totalExpenses;
    std::vector<std::pair<std::string, double>> expenseRecords;

public:
    ExpenseTracker();

    void addExpense(const std::string& description, double amount);
    void removeExpense(int index);
    double getTotalExpenses() const;
    double getExpensesByCategory(const std::string& category) const;
};

class ProfitAnalyzer {
private:
    double totalRevenue;
    double totalCosts;
    std::vector<double> monthlyProfits;

public:
    ProfitAnalyzer();

    void addRevenue(double amount);
    void addCost(double amount);
    double calculateProfit() const;
    double calculateProfitMargin() const;
    void addMonthlyProfit(double profit);
    double getAverageMonthlyProfit() const;
};

class TaxCalculator {
private:
    double taxRate;
    double deductibleExpenses;

public:
    TaxCalculator(double rate = 0.20); // 20% налог

    double calculateTax(double revenue, double expenses) const;
    void addDeductibleExpense(double amount);
    void resetDeductibleExpenses();

    double getTaxRate() const { return taxRate; }
    void setTaxRate(double rate) { taxRate = rate; }
};

#endif // COMPANYFINANCE_H