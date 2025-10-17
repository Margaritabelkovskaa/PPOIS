#include "rubiks_cube.h"
#include <iostream>
#include <random>

RubiksCube::RubiksCube() {
    front = std::vector<std::vector<Color>>(3, std::vector<Color>(3));
    back = std::vector<std::vector<Color>>(3, std::vector<Color>(3));
    left = std::vector<std::vector<Color>>(3, std::vector<Color>(3));
    right = std::vector<std::vector<Color>>(3, std::vector<Color>(3));
    up = std::vector<std::vector<Color>>(3, std::vector<Color>(3));
    down = std::vector<std::vector<Color>>(3, std::vector<Color>(3));
    initialize();
}

void RubiksCube::initialize() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            front[i][j] = Color::RED;
            back[i][j] = Color::ORANGE;
            left[i][j] = Color::GREEN;
            right[i][j] = Color::BLUE;
            up[i][j] = Color::WHITE;
            down[i][j] = Color::YELLOW;
        }
    }
}

void RubiksCube::rotateFaceClockwise(std::vector<std::vector<Color>>& face) {
    std::vector<std::vector<Color>> temp = face;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            face[i][j] = temp[2 - j][i];
        }
    }
}

void RubiksCube::rotateFaceCounterClockwise(std::vector<std::vector<Color>>& face) {
    std::vector<std::vector<Color>> temp = face;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            face[i][j] = temp[j][2 - i];
        }
    }
}

void RubiksCube::rotateFrontClockwise() {
    rotateFaceClockwise(front);
    std::vector<Color> temp = up[2];
    for (int i = 0; i < 3; i++) {
        up[2][i] = left[2 - i][2];
        left[2 - i][2] = down[0][2 - i];
        down[0][2 - i] = right[i][0];
        right[i][0] = temp[i];
    }
}

void RubiksCube::rotateFrontCounterClockwise() {
    rotateFaceCounterClockwise(front);
    std::vector<Color> temp = up[2];
    for (int i = 0; i < 3; i++) {
        up[2][i] = right[i][0];
        right[i][0] = down[0][2 - i];
        down[0][2 - i] = left[2 - i][2];
        left[2 - i][2] = temp[i];
    }
}

void RubiksCube::rotateRightClockwise() {
    rotateFaceClockwise(right);
    std::vector<Color> temp;
    for (int i = 0; i < 3; i++) {
        temp.push_back(up[i][2]);
    }
    for (int i = 0; i < 3; i++) {
        up[i][2] = front[i][2];
        front[i][2] = down[i][2];
        down[i][2] = back[2 - i][0];
        back[2 - i][0] = temp[i];
    }
}

void RubiksCube::rotateRightCounterClockwise() {
    rotateFaceCounterClockwise(right);
    std::vector<Color> temp;
    for (int i = 0; i < 3; i++) {
        temp.push_back(up[i][2]);
    }
    for (int i = 0; i < 3; i++) {
        up[i][2] = back[2 - i][0];
        back[2 - i][0] = down[i][2];
        down[i][2] = front[i][2];
        front[i][2] = temp[i];
    }
}

void RubiksCube::rotateLeftClockwise() {
    rotateFaceClockwise(left);
    std::vector<Color> temp;
    for (int i = 0; i < 3; i++) {
        temp.push_back(up[i][0]);
    }
    for (int i = 0; i < 3; i++) {
        up[i][0] = back[2 - i][2];
        back[2 - i][2] = down[i][0];
        down[i][0] = front[i][0];
        front[i][0] = temp[i];
    }
}

void RubiksCube::rotateLeftCounterClockwise() {
    rotateFaceCounterClockwise(left);
    std::vector<Color> temp;
    for (int i = 0; i < 3; i++) {
        temp.push_back(up[i][0]);
    }
    for (int i = 0; i < 3; i++) {
        up[i][0] = front[i][0];
        front[i][0] = down[i][0];
        down[i][0] = back[2 - i][2];
        back[2 - i][2] = temp[i];
    }
}

void RubiksCube::rotateUpClockwise() {
    rotateFaceClockwise(up);
    std::vector<Color> temp = front[0];
    for (int i = 0; i < 3; i++) {
        front[0][i] = right[0][i];
        right[0][i] = back[0][i];
        back[0][i] = left[0][i];
        left[0][i] = temp[i];
    }
}

void RubiksCube::rotateUpCounterClockwise() {
    rotateFaceCounterClockwise(up);
    std::vector<Color> temp = front[0];
    for (int i = 0; i < 3; i++) {
        front[0][i] = left[0][i];
        left[0][i] = back[0][i];
        back[0][i] = right[0][i];
        right[0][i] = temp[i];
    }
}

void RubiksCube::rotateDownClockwise() {
    rotateFaceClockwise(down);
    std::vector<Color> temp = front[2];
    for (int i = 0; i < 3; i++) {
        front[2][i] = left[2][i];
        left[2][i] = back[2][i];
        back[2][i] = right[2][i];
        right[2][i] = temp[i];
    }
}

void RubiksCube::rotateDownCounterClockwise() {
    rotateFaceCounterClockwise(down);
    std::vector<Color> temp = front[2];
    for (int i = 0; i < 3; i++) {
        front[2][i] = right[2][i];
        right[2][i] = back[2][i];
        back[2][i] = left[2][i];
        left[2][i] = temp[i];
    }
}

void RubiksCube::rotateBackClockwise() {
    rotateFaceClockwise(back);
    std::vector<Color> temp = up[0];
    for (int i = 0; i < 3; i++) {
        up[0][i] = right[i][2];
        right[i][2] = down[2][2 - i];
        down[2][2 - i] = left[2 - i][0];
        left[2 - i][0] = temp[i];
    }
}

void RubiksCube::rotateBackCounterClockwise() {
    rotateFaceCounterClockwise(back);
    std::vector<Color> temp = up[0];
    for (int i = 0; i < 3; i++) {
        up[0][i] = left[2 - i][0];
        left[2 - i][0] = down[2][2 - i];
        down[2][2 - i] = right[i][2];
        right[i][2] = temp[i];
    }
}

void RubiksCube::scramble(int moves) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 11);
    for (int i = 0; i < moves; i++) {
        int choice = dis(gen);
        switch (choice) {
        case 0: rotateFrontClockwise(); break;
        case 1: rotateFrontCounterClockwise(); break;
        case 2: rotateRightClockwise(); break;
        case 3: rotateRightCounterClockwise(); break;
        case 4: rotateLeftClockwise(); break;
        case 5: rotateLeftCounterClockwise(); break;
        case 6: rotateUpClockwise(); break;
        case 7: rotateUpCounterClockwise(); break;
        case 8: rotateDownClockwise(); break;
        case 9: rotateDownCounterClockwise(); break;
        case 10: rotateBackClockwise(); break;
        case 11: rotateBackCounterClockwise(); break;
        }
    }
}

bool RubiksCube::isSolved() {
    return isFaceUniform(front) && isFaceUniform(back) &&
        isFaceUniform(left) && isFaceUniform(right) &&
        isFaceUniform(up) && isFaceUniform(down);
}

bool RubiksCube::isFaceUniform(const std::vector<std::vector<Color>>& face) {
    Color firstColor = face[0][0];
    for (const auto& row : face) {
        for (Color color : row) {
            if (color != firstColor) {
                return false;
            }
        }
    }
    return true;
}

char RubiksCube::colorToChar(Color color) {
    switch (color) {
    case Color::WHITE: return 'W';
    case Color::YELLOW: return 'Y';
    case Color::RED: return 'R';
    case Color::ORANGE: return 'O';
    case Color::GREEN: return 'G';
    case Color::BLUE: return 'B';
    default: return ' ';
    }
}

void RubiksCube::printRow(const std::vector<Color>& row) {
    for (Color color : row) {
        std::cout << colorToChar(color) << " ";
    }
}

void RubiksCube::printFace(const std::vector<std::vector<Color>>& face) {
    for (const auto& row : face) {
        std::cout << "  ";
        printRow(row);
        std::cout << std::endl;
    }
}

void RubiksCube::display() {
    std::cout << "Êóáèê-ðóáèê:\n" << std::endl;
    std::cout << "Ââåðõ(áåëûé):" << std::endl;
    printFace(up);
    std::cout << std::endl;
    std::cout << "Ñåðåäèíà:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "  ";
        printRow(left[i]);
        std::cout << " ";
        printRow(front[i]);
        std::cout << " ";
        printRow(right[i]);
        std::cout << " ";
        printRow(back[i]);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Íèç(æåëòûé):" << std::endl;
    printFace(down);
}
