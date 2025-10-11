#ifndef RUBIKS_CUBE_H
#define RUBIKS_CUBE_H

#include <vector>
 class Color {
    WHITE = 0,
    YELLOW = 1,
    RED = 2,
    ORANGE = 3,
    GREEN = 4,
    BLUE = 5,
    NONE = 6
};

class RubiksCube {
private:
    std::vector<std::vector<Color>> front;
    std::vector<std::vector<Color>> back;
    std::vector<std::vector<Color>> left;
    std::vector<std::vector<Color>> right;
    std::vector<std::vector<Color>> up;
    std::vector<std::vector<Color>> down;

    void rotateFaceClockwise(std::vector<std::vector<Color>>& face);
    void rotateFaceCounterClockwise(std::vector<std::vector<Color>>& face);
    bool isFaceUniform(const std::vector<std::vector<Color>>& face);
    char colorToChar(Color color);
    void printRow(const std::vector<Color>& row);
    void printFace(const std::vector<std::vector<Color>>& face);

public:
    RubiksCube();
    void initialize();

    // Ïîâîðîòû ãðàíåé
    void rotateFrontClockwise();
    void rotateFrontCounterClockwise();
    void rotateRightClockwise();
    void rotateRightCounterClockwise();
    void rotateLeftClockwise();
    void rotateLeftCounterClockwise();
    void rotateUpClockwise();
    void rotateUpCounterClockwise();
    void rotateDownClockwise();
    void rotateDownCounterClockwise();
    void rotateBackClockwise();
    void rotateBackCounterClockwise();

    void scramble(int moves = 20);
    bool isSolved();
    void display();
};


#endif
