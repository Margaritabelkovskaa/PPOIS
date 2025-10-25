#include "CompanyFinance.h"
#include <algorithm>
#include <stdexcept>
// ExpenseTracker
ExpenseTracker::ExpenseTracker() : totalExpenses(0.0) {}

void ExpenseTracker::addExpense(const std::string& description, double amount) {
    if (amount < 0) throw std::invalid_argument("Expense amount cannot be negative");
    expenseRecords.push_back({ description, amount });
    totalExpenses += amount;
}

void ExpenseTracker::removeExpense(int index) {
    if (index >= 0 && index < expenseRecords.size()) {
        totalExpenses -= expenseRecords[index].second;
        expenseRecords.erase(expenseRecords.begin() + index);
    }
}

double ExpenseTracker::getTotalExpenses() const {
    return totalExpenses;
}

double ExpenseTracker::getExpensesByCategory(const std::string& category) const {
    double sum = 0.0;
    for (const auto& record : expenseRecords) {
        if (record.first.find(category) != std::string::npos) {
            sum += record.second;
        }
    }
    return sum;
}

// ProfitAnalyzer
ProfitAnalyzer::ProfitAnalyzer() : totalRevenue(0.0), totalCosts(0.0) {}

void ProfitAnalyzer::addRevenue(double amount) {
    if (amount < 0) throw std::invalid_argument("Revenue cannot be negative");
    totalRevenue += amount;
}

void ProfitAnalyzer::addCost(double amount) {
    if (amount < 0) throw std::invalid_argument("Cost cannot be negative");
    totalCosts += amount;
}

double ProfitAnalyzer::calculateProfit() const {
    return totalRevenue - totalCosts;
}

double ProfitAnalyzer::calculateProfitMargin() const {
    if (totalRevenue == 0) return 0.0;
    return (calculateProfit() / totalRevenue) * 100.0;
}

void ProfitAnalyzer::addMonthlyProfit(double profit) {
    monthlyProfits.push_back(profit);
}

double ProfitAnalyzer::getAverageMonthlyProfit() const {
    if (monthlyProfits.empty()) return 0.0;

    double sum = 0.0;
    for (double profit : monthlyProfits) {
        sum += profit;
    }
    return sum / monthlyProfits.size();
}

// TaxCalculator
TaxCalculator::TaxCalculator(double rate) : taxRate(rate), deductibleExpenses(0.0) {}

double TaxCalculator::calculateTax(double revenue, double expenses) const {
    double taxableIncome = revenue - expenses - deductibleExpenses;
    if (taxableIncome <= 0) return 0.0;
    return taxableIncome * taxRate;
}

void TaxCalculator::addDeductibleExpense(double amount) {
    if (amount < 0) throw std::invalid_argument("Deductible expense cannot be negative");
    deductibleExpenses += amount;
}

void TaxCalculator::resetDeductibleExpenses() {
    deductibleExpenses = 0.0;
}