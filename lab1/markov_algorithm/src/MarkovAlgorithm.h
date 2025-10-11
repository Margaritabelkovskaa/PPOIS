#ifndef MARKOV_ALGORITHM_H
#define MARKOV_ALGORITHM_H

#include <string>
#include <vector>

using namespace std;

class MarkovAlgorithm {
private:
    struct Rule {
        string from;
        string to;
        bool is_final;

        Rule(const string& f, const string& t, bool final = false)
            : from(f), to(t), is_final(final) {
        }
    };

    vector<Rule> rules;

    void validateRule(const string& from);
    bool processIteration(string& current);
    void findApplicableRule(const string& current,
        bool& rule_applied,
        bool& final_rule_applied,
        string& result);
    void applyRule(const string& current,
        const Rule& rule,
        size_t pos,
        string& result);
    void checkMaxSteps(int steps);
    void printAllRules() const;
    void printSingleRule(size_t index) const;

public:
    void addRule(const string& from, const string& to, bool is_final = false);
    string execute(const string& input);
    void clear();
    void printRules() const;
};

#endif
