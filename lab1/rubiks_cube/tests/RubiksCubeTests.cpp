#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include "RubiksCube.h"

using namespace std;

// 1. Тест начального состояния
TEST(RubiksCubeTest, InitialStateIsSolved) {
    RubiksCube cube;
    EXPECT_TRUE(cube.isSolved());
}

// 2. Тест поворота передней грани по часовой и обратно
TEST(RubiksCubeTest, FrontClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateFrontClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateFrontCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 3. Тест четырех поворотов передней грани по часовой
TEST(RubiksCubeTest, FourFrontClockwiseRotations) {
    RubiksCube cube;
    for (int i = 0; i < 4; i++) {
        cube.rotateFrontClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 4. Тест поворота правой грани по часовой и обратно
TEST(RubiksCubeTest, RightClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateRightClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateRightCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 5. Тест четырех поворотов правой грани
TEST(RubiksCubeTest, FourRightClockwiseRotations) {
    RubiksCube cube;
    for (int i = 0; i < 4; i++) {
        cube.rotateRightClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 6. Тест поворота левой грани
TEST(RubiksCubeTest, LeftClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateLeftClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateLeftCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 7. Тест верхней грани
TEST(RubiksCubeTest, UpClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateUpClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateUpCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 8. Тест нижней грани
TEST(RubiksCubeTest, DownClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateDownClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateDownCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 9. Тест задней грани
TEST(RubiksCubeTest, BackClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateBackClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateBackCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 10. Тест комбинации R U R' U'
TEST(RubiksCubeTest, RURPrimeUPrimeSequence) {
    RubiksCube cube;

    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpCounterClockwise();

    EXPECT_FALSE(cube.isSolved());

    for (int i = 0; i < 5; i++) {
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
        cube.rotateRightCounterClockwise();
        cube.rotateUpCounterClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 11. Тест перемешивания и сброса
TEST(RubiksCubeTest, ScrambleAndReset) {
    RubiksCube cube;
    cube.scramble(10);
    EXPECT_FALSE(cube.isSolved());

    cube.initialize();
    EXPECT_TRUE(cube.isSolved());
}

// 12. Тест множественного перемешивания
TEST(RubiksCubeTest, MultipleScrambles) {
    RubiksCube cube;
    for (int i = 0; i < 5; i++) {
        cube.scramble(15);
        EXPECT_FALSE(cube.isSolved());
        cube.initialize();
        EXPECT_TRUE(cube.isSolved());
    }
}

// 13. Тест комбинации F R U B L D
TEST(RubiksCubeTest, FRUBLDSequence) {
    RubiksCube cube;
    cube.rotateFrontClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateBackClockwise();
    cube.rotateLeftClockwise();
    cube.rotateDownClockwise();

    EXPECT_FALSE(cube.isSolved());
}

// 14. Тест обратной комбинации D' L' B' U' R' F'
TEST(RubiksCubeTest, ReverseFRUBLDSequence) {
    RubiksCube cube;

    cube.rotateFrontClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateBackClockwise();
    cube.rotateLeftClockwise();
    cube.rotateDownClockwise();

    cube.rotateDownCounterClockwise();
    cube.rotateLeftCounterClockwise();
    cube.rotateBackCounterClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateFrontCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 15. Тест базового алгоритма сборки
TEST(RubiksCubeTest, BasicAlgorithm) {
    RubiksCube cube;
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpCounterClockwise();

    EXPECT_FALSE(cube.isSolved());

    cube.rotateUpClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 16. Тест T-пермутации
TEST(RubiksCubeTest, TPermutation) {
    RubiksCube cube;
    vector<function<void()>> moves = {
        [&]() { cube.rotateRightClockwise(); },
        [&]() { cube.rotateUpClockwise(); },
        [&]() { cube.rotateRightCounterClockwise(); },
        [&]() { cube.rotateUpCounterClockwise(); },
        [&]() { cube.rotateRightCounterClockwise(); },
        [&]() { cube.rotateFrontClockwise(); },
        [&]() { cube.rotateRightClockwise(); cube.rotateRightClockwise(); },
        [&]() { cube.rotateUpCounterClockwise(); },
        [&]() { cube.rotateRightCounterClockwise(); },
        [&]() { cube.rotateUpCounterClockwise(); },
        [&]() { cube.rotateRightClockwise(); },
        [&]() { cube.rotateUpClockwise(); },
        [&]() { cube.rotateRightCounterClockwise(); },
        [&]() { cube.rotateFrontCounterClockwise(); }
    };

    for (auto& move : moves) move();
    EXPECT_FALSE(cube.isSolved());

    for (auto& move : moves) move();
    EXPECT_TRUE(cube.isSolved());
}

// 17. Тест перемешивания разной длины
TEST(RubiksCubeTest, DifferentScrambleLengths) {
    RubiksCube cube1, cube2, cube3;

    cube1.scramble(5);
    bool state5 = cube1.isSolved();

    cube2.scramble(20);
    bool state20 = cube2.isSolved();

    cube3.scramble(50);
    bool state50 = cube3.isSolved();

    EXPECT_FALSE(state5 || state20 || state50);
}

// 18. Тест повторной инициализации
TEST(RubiksCubeTest, Reinitialization) {
    RubiksCube cube;

    cube.scramble(25);
    cube.initialize();
    EXPECT_TRUE(cube.isSolved());

    cube.scramble(30);
    cube.initialize();
    EXPECT_TRUE(cube.isSolved());
}

// 19. Тест граничных значений перемешивания
TEST(RubiksCubeTest, BoundaryScrambleValues) {
    RubiksCube cube1, cube2;

    cube1.scramble(0);
    EXPECT_TRUE(cube1.isSolved());

    cube2.scramble(1);
    EXPECT_FALSE(cube2.isSolved());
}

// 20. Тест сложной комбинации
TEST(RubiksCubeTest, ComplexCombination) {
    RubiksCube cube;

    for (int i = 0; i < 6; i++) {
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
        cube.rotateRightCounterClockwise();
        cube.rotateUpCounterClockwise();
    }

    EXPECT_TRUE(cube.isSolved());
}

// 21. Тест проверки после каждого хода
TEST(RubiksCubeTest, CheckAfterEachMove) {
    RubiksCube cube;

    cube.rotateFrontClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateRightClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateUpClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateLeftClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateDownClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateBackClockwise();
    EXPECT_FALSE(cube.isSolved());
}

// 22. Тест симметричных последовательностей
TEST(RubiksCubeTest, SymmetricSequences) {
    RubiksCube cube;

    vector<function<void()>> moves = {
        [&]() { cube.rotateFrontClockwise(); },
        [&]() { cube.rotateFrontCounterClockwise(); },
        [&]() { cube.rotateRightClockwise(); },
        [&]() { cube.rotateRightCounterClockwise(); },
        [&]() { cube.rotateUpClockwise(); },
        [&]() { cube.rotateUpCounterClockwise(); },
        [&]() { cube.rotateLeftClockwise(); },
        [&]() { cube.rotateLeftCounterClockwise(); },
        [&]() { cube.rotateDownClockwise(); },
        [&]() { cube.rotateDownCounterClockwise(); },
        [&]() { cube.rotateBackClockwise(); },
        [&]() { cube.rotateBackCounterClockwise(); }
    };

    for (auto& move : moves) move();
    EXPECT_TRUE(cube.isSolved());
}

// 23. Тест обратного чередования
TEST(RubiksCubeTest, ReverseAlternatingMoves) {
    RubiksCube cube;

    for (int i = 0; i < 4; i++) {
        cube.rotateRightCounterClockwise();
        cube.rotateFrontCounterClockwise();
        cube.rotateRightClockwise();
        cube.rotateFrontClockwise();
    }

    EXPECT_TRUE(cube.isSolved());
}

// 24. Тест проверки состояния после reset
TEST(RubiksCubeTest, StateAfterReset) {
    RubiksCube cube;

    cube.scramble(100);
    bool scrambled = cube.isSolved();

    cube.initialize();
    bool reset = cube.isSolved();

    EXPECT_FALSE(scrambled);
    EXPECT_TRUE(reset);
}

// 25. Тест последовательности для проверки целостности
TEST(RubiksCubeTest, IntegrityCheckSequence) {
    RubiksCube cube;

    for (int i = 0; i < 3; i++) {
        cube.rotateFrontClockwise();
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
        cube.rotateBackClockwise();
        cube.rotateLeftClockwise();
        cube.rotateDownClockwise();
    }

    EXPECT_FALSE(cube.isSolved());

    for (int i = 0; i < 3; i++) {
        cube.rotateDownCounterClockwise();
        cube.rotateLeftCounterClockwise();
        cube.rotateBackCounterClockwise();
        cube.rotateUpCounterClockwise();
        cube.rotateRightCounterClockwise();
        cube.rotateFrontCounterClockwise();
    }

    EXPECT_TRUE(cube.isSolved());
}

// 26. Тест экстремального перемешивания
TEST(RubiksCubeTest, ExtremeScrambling) {
    RubiksCube cube;

    cube.scramble(1000);
    EXPECT_FALSE(cube.isSolved());

    cube.initialize();
    EXPECT_TRUE(cube.isSolved());
}

// 27. Тест на идентичность двух последовательностей
TEST(RubiksCubeTest, SequenceEquivalence) {
    RubiksCube cube1, cube2;

    cube1.rotateFrontClockwise();
    cube1.rotateRightClockwise();

    cube2.rotateFrontClockwise();
    cube2.rotateRightClockwise();

    EXPECT_EQ(cube1.isSolved(), cube2.isSolved());
}

// 28. Тест инверсных операций
TEST(RubiksCubeTest, InverseOperations) {
    RubiksCube cube;

    cube.rotateFrontClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateBackClockwise();

    EXPECT_FALSE(cube.isSolved());

    cube.rotateBackCounterClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateFrontCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 29. Тест комбинации с повторяющимися ходами
TEST(RubiksCubeTest, RepeatedMovesCombination) {
    RubiksCube cube;

    for (int i = 0; i < 4; i++) cube.rotateFrontClockwise();
    EXPECT_TRUE(cube.isSolved());

    for (int i = 0; i < 4; i++) cube.rotateRightClockwise();
    EXPECT_TRUE(cube.isSolved());

    for (int i = 0; i < 4; i++) cube.rotateUpClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 30. Тест сложной восстановительной последовательности
TEST(RubiksCubeTest, ComplexRecoverySequence) {
    RubiksCube cube;

    cube.rotateFrontClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpClockwise();
    cube.rotateBackCounterClockwise();
    cube.rotateLeftClockwise();
    cube.rotateDownCounterClockwise();
    cube.rotateFrontCounterClockwise();
    cube.rotateRightClockwise();

    EXPECT_FALSE(cube.isSolved());

    cube.rotateRightCounterClockwise();
    cube.rotateFrontClockwise();
    cube.rotateDownClockwise();
    cube.rotateLeftCounterClockwise();
    cube.rotateBackClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightClockwise();
    cube.rotateFrontCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
