#include "markov_algorithm.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void MarkovAlgorithm::addRule(const string& from, const string& to, bool is_final) {
    validateRule(from);
    rules.push_back(Rule(from, to, is_final));
}

void MarkovAlgorithm::validateRule(const string& from) {
    if (from.empty()) {
        throw invalid_argument("Left part of rule cannot be empty");
    }
}

string MarkovAlgorithm::execute(const string& input) {
    string current = input;
    int steps = 0;
    const int MAX_STEPS = 1000;

    while (steps < MAX_STEPS) {
        bool shouldContinue = processIteration(current);
        if (!shouldContinue) break;
        steps++;
    }

    checkMaxSteps(steps);
    return current;
}

bool MarkovAlgorithm::processIteration(string& current) {
    bool rule_applied = false;
    bool final_rule_applied = false;
    string next_string = current;

    findApplicableRule(current, rule_applied, final_rule_applied, next_string);

    if (!rule_applied) {
        return false;
    }

    current = next_string;
    return !final_rule_applied;
}

void MarkovAlgorithm::findApplicableRule(const string& current,
    bool& rule_applied,
    bool& final_rule_applied,
    string& result) {
    for (const auto& rule : rules) {
        size_t pos = current.find(rule.from);
        if (pos != string::npos) {
            applyRule(current, rule, pos, result);
            rule_applied = true;
            final_rule_applied = rule.is_final;
            break;
        }
    }
}

void MarkovAlgorithm::applyRule(const string& current,
    const Rule& rule,
    size_t pos,
    string& result) {
    string before = current.substr(0, pos);
    string after = current.substr(pos + rule.from.length());
    result = before + rule.to + after;
}

void MarkovAlgorithm::checkMaxSteps(int steps) {
    if (steps >= 1000) {
        throw runtime_error("Too many iterations");
    }
}

void MarkovAlgorithm::clear() {
    rules.clear();
}

void MarkovAlgorithm::printRules() const {
    if (rules.empty()) {
        cout << "No rules" << endl;
        return;
    }

    printAllRules();
}

void MarkovAlgorithm::printAllRules() const {
    for (size_t i = 0; i < rules.size(); i++) {
        printSingleRule(i);
    }
}

void MarkovAlgorithm::printSingleRule(size_t index) const {
    cout << (index + 1) << ". " << rules[index].from << " -> ";
    if (rules[index].is_final) {
        cout << ". ";
    }
    cout << rules[index].to << endl;
}