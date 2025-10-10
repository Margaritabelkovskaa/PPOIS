#include <iostream>
#include <string>
#include "rubiks_cube.h"

int getInput() {
    int choice;
    while (true) {
        std::cout << "Enter your choice: ";
        if (std::cin >> choice) {
            return choice;
        }
        else {
            std::cout << "Please enter a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

void displayMainMenu() {
    std::cout << "\n" << std::string(40, '=') << std::endl;
    std::cout << "        RUBIK'S CUBE SIMULATOR" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "1. Rotate face" << std::endl;
    std::cout << "2. Display cube" << std::endl;
    std::cout << "3. Scramble cube" << std::endl;
    std::cout << "4. Check if solved" << std::endl;
    std::cout << "5. Reset to initial state" << std::endl;
    std::cout << "0. EXIT" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
}

void displayFaceMenu() {
    std::cout << "\n" << std::string(30, '-') << std::endl;
    std::cout << "    SELECT FACE TO ROTATE" << std::endl;
    std::cout << std::string(30, '-') << std::endl;
    std::cout << "1. FRONT" << std::endl;
    std::cout << "2. RIGHT" << std::endl;
    std::cout << "3. LEFT" << std::endl;
    std::cout << "4. UP" << std::endl;
    std::cout << "5. DOWN" << std::endl;
    std::cout << "6. BACK" << std::endl;
    std::cout << "0. BACK TO MAIN MENU" << std::endl;
    std::cout << std::string(30, '-') << std::endl;
}

void displayDirectionMenu() {
    std::cout << "\n" << std::string(30, '-') << std::endl;
    std::cout << "    SELECT ROTATION DIRECTION" << std::endl;
    std::cout << std::string(30, '-') << std::endl;
    std::cout << "1. CLOCKWISE" << std::endl;
    std::cout << "2. COUNTER-CLOCKWISE" << std::endl;
    std::cout << "0. BACK TO FACE SELECTION" << std::endl;
    std::cout << std::string(30, '-') << std::endl;
}

void rotateFace(RubiksCube& cube) {
    int faceChoice, directionChoice;

    while (true) {
        displayFaceMenu();
        faceChoice = getInput();

        if (faceChoice == 0) return;

        if (faceChoice < 1 || faceChoice > 6) {
            std::cout << "Invalid face selection!" << std::endl;
            continue;
        }

        displayDirectionMenu();
        directionChoice = getInput();

        if (directionChoice == 0) continue;

        if (directionChoice < 1 || directionChoice > 2) {
            std::cout << "Invalid direction selection!" << std::endl;
            continue;
        }

        // Execute rotation based on selections
        switch (faceChoice) {
        case 1: // FRONT
            if (directionChoice == 1) {
                cube.rotateFrontClockwise();
                std::cout << "Front face rotated CLOCKWISE" << std::endl;
            }
            else {
                cube.rotateFrontCounterClockwise();
                std::cout << "Front face rotated COUNTER-CLOCKWISE" << std::endl;
            }
            break;
        case 2: // RIGHT
            if (directionChoice == 1) {
                cube.rotateRightClockwise();
                std::cout << "Right face rotated CLOCKWISE" << std::endl;
            }
            else {
                cube.rotateRightCounterClockwise();
                std::cout << "Right face rotated COUNTER-CLOCKWISE" << std::endl;
            }
            break;
        case 3: // LEFT
            if (directionChoice == 1) {
                cube.rotateLeftClockwise();
                std::cout << "Left face rotated CLOCKWISE" << std::endl;
            }
            else {
                cube.rotateLeftCounterClockwise();
                std::cout << "Left face rotated COUNTER-CLOCKWISE" << std::endl;
            }
            break;
        case 4: // UP
            if (directionChoice == 1) {
                cube.rotateUpClockwise();
                std::cout << "Up face rotated CLOCKWISE" << std::endl;
            }
            else {
                cube.rotateUpCounterClockwise();
                std::cout << "Up face rotated COUNTER-CLOCKWISE" << std::endl;
            }
            break;
        case 5: // DOWN
            if (directionChoice == 1) {
                cube.rotateDownClockwise();
                std::cout << "Down face rotated CLOCKWISE" << std::endl;
            }
            else {
                cube.rotateDownCounterClockwise();
                std::cout << "Down face rotated COUNTER-CLOCKWISE" << std::endl;
            }
            break;
        case 6: // BACK
            if (directionChoice == 1) {
                cube.rotateBackClockwise();
                std::cout << "Back face rotated CLOCKWISE" << std::endl;
            }
            else {
                cube.rotateBackCounterClockwise();
                std::cout << "Back face rotated COUNTER-CLOCKWISE" << std::endl;
            }
            break;
        }

        // Show the result
        cube.display();
        return;
    }
}

int main() {
    RubiksCube cube;

    while (true) {
        displayMainMenu();
        int choice = getInput();

        if (choice == 0) {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        switch (choice) {
        case 1:
            rotateFace(cube);
            break;
        case 2:
            cube.display();
            break;
        case 3: {
            std::cout << "How many scrambles? (default 20): ";
            std::string input;
            std::cin >> input;
            int moves = 20;
            try { moves = std::stoi(input); }
            catch (...) { moves = 20; }
            cube.scramble(moves);
            std::cout << "Cube scrambled (" << moves << " moves)" << std::endl;
            cube.display();
            break;
        }
        case 4:
            if (cube.isSolved())
                std::cout << "🎉 Cube is SOLVED! 🎉" << std::endl;
            else
                std::cout << "Cube is NOT solved" << std::endl;
            break;
        case 5:
            cube.initialize();
            std::cout << "Cube reset to initial state" << std::endl;
            cube.display();
            break;
        default:
            std::cout << "Invalid option!" << std::endl;
            break;
        }
    }
    return 0;
}