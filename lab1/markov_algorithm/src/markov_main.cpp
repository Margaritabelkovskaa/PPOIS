#include <iostream>
#include "markov_algorithm.h"

using namespace std;

int main() {
    MarkovAlgorithm algo;
    int choice;

    do {
        cout << "\n=== Markov Algorithm Tester ===" << endl;
        cout << "1. Add rule" << endl;
        cout << "2. Clear all rules" << endl;
        cout << "3. Execute on string" << endl;
        cout << "4. Show current rules" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string from, to;
            char final_flag;

            cout << "Enter left part: ";
            getline(cin, from);
            cout << "Enter right part: ";
            getline(cin, to);
            cout << "Is final rule? (y/n): ";
            cin >> final_flag;
            cin.ignore();

            try {
                algo.addRule(from, to, (final_flag == 'y' || final_flag == 'Y'));
                cout << "Rule added successfully!" << endl;
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 2:
            algo.clear();
            cout << "All rules cleared!" << endl;
            break;

        case 3: {
            string input;
            cout << "Enter input string: ";
            getline(cin, input);

            try {
                string result = algo.execute(input);
                cout << "Result: " << result << endl;
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 4:
            algo.printRules();
            break;

        case 0:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}