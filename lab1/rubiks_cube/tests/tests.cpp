// tests_rubiks_cube_no_header.cpp
#include <gtest/gtest.h>
#include <vector>
#include <functional>
#include <chrono>
#include "rubiks_cube.h"

// 1. ���� ���������� ���������
TEST(RubiksCubeTest, InitialStateIsSolved) {
    RubiksCube cube;
    EXPECT_TRUE(cube.isSolved());
}

// 2. ���� �������� �������� ����� �� ������� � �������
TEST(RubiksCubeTest, FrontClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateFrontClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateFrontCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 3. ���� ������� ��������� �������� ����� �� �������
TEST(RubiksCubeTest, FourFrontClockwiseRotations) {
    RubiksCube cube;
    for (int i = 0; i < 4; i++) {
        cube.rotateFrontClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 4. ���� �������� ������ ����� �� ������� � �������
TEST(RubiksCubeTest, RightClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateRightClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateRightCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 5. ���� ������� ��������� ������ �����
TEST(RubiksCubeTest, FourRightClockwiseRotations) {
    RubiksCube cube;
    for (int i = 0; i < 4; i++) {
        cube.rotateRightClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 6. ���� �������� ����� �����
TEST(RubiksCubeTest, LeftClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateLeftClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateLeftCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 7. ���� ������� �����
TEST(RubiksCubeTest, UpClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateUpClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateUpCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 8. ���� ������ �����
TEST(RubiksCubeTest, DownClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateDownClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateDownCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 9. ���� ������ �����
TEST(RubiksCubeTest, BackClockwiseCounterClockwise) {
    RubiksCube cube;
    cube.rotateBackClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.rotateBackCounterClockwise();
    EXPECT_TRUE(cube.isSolved());
}

// 10. ���� ���������� R U R' U'
TEST(RubiksCubeTest, RURPrimeUPrimeSequence) {
    RubiksCube cube;

    // R U R' U'
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpCounterClockwise();

    EXPECT_FALSE(cube.isSolved());

    // ��������� ������������������ ��� 5 ��� (����� 6) ��� �������� � �������� ���������
    for (int i = 0; i < 5; i++) {
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
        cube.rotateRightCounterClockwise();
        cube.rotateUpCounterClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 11. ���� ������������� � ������
TEST(RubiksCubeTest, ScrambleAndReset) {
    RubiksCube cube;
    cube.scramble(10);
    EXPECT_FALSE(cube.isSolved());

    cube.initialize();
    EXPECT_TRUE(cube.isSolved());
}

// 12. ���� �������������� �������������
TEST(RubiksCubeTest, MultipleScrambles) {
    RubiksCube cube;
    for (int i = 0; i < 5; i++) {
        cube.scramble(15);
        EXPECT_FALSE(cube.isSolved());
        cube.initialize();
        EXPECT_TRUE(cube.isSolved());
    }
}

// 13. ���� ���������� F R U B L D
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

// 14. ���� �������� ���������� D' L' B' U' R' F'
TEST(RubiksCubeTest, ReverseFRUBLDSequence) {
    RubiksCube cube;

    // F R U B L D
    cube.rotateFrontClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateBackClockwise();
    cube.rotateLeftClockwise();
    cube.rotateDownClockwise();

    // D' L' B' U' R' F'
    cube.rotateDownCounterClockwise();
    cube.rotateLeftCounterClockwise();
    cube.rotateBackCounterClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateFrontCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 15. ���� ��������� "����� ���"
TEST(RubiksCubeTest, SexyMoveAlgorithm) {
    RubiksCube cube;
    // R U R' U' - ��������� ��������
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpCounterClockwise();

    EXPECT_FALSE(cube.isSolved());

    // �������� ��������
    cube.rotateUpClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 16. ���� T-����������
TEST(RubiksCubeTest, TPermutation) {
    RubiksCube cube;
    // R U R' U' R' F R2 U' R' U' R U R' F'
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateFrontClockwise();
    cube.rotateRightClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateFrontCounterClockwise();

    EXPECT_FALSE(cube.isSolved());

    // ������� ���������� T-���������� ������ ������� � �������� ���������
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateFrontClockwise();
    cube.rotateRightClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateFrontCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 17. ���� ������������� ������ �����
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

// 18. ���� ��������� �������������
TEST(RubiksCubeTest, Reinitialization) {
    RubiksCube cube;

    cube.scramble(25);
    cube.initialize();
    EXPECT_TRUE(cube.isSolved());

    cube.scramble(30);
    cube.initialize();
    EXPECT_TRUE(cube.isSolved());
}

// 19. ���� ��������� �������� �������������
TEST(RubiksCubeTest, BoundaryScrambleValues) {
    RubiksCube cube1, cube2;

    cube1.scramble(0);
    EXPECT_TRUE(cube1.isSolved());

    cube2.scramble(1);
    EXPECT_FALSE(cube2.isSolved());
}

// 20. ���� ������� ����������
TEST(RubiksCubeTest, ComplexCombination) {
    RubiksCube cube;

    // R2 U2 R2 U2 R2 U2
    for (int i = 0; i < 3; i++) {
        cube.rotateRightClockwise();
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
        cube.rotateUpClockwise();
    }

    EXPECT_TRUE(cube.isSolved()); // ������ �������� ��������
}

// 21. ���� �������� ����� ������� ����
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

// 22. ���� ������������ �������������������
TEST(RubiksCubeTest, SymmetricSequences) {
    RubiksCube cube;

    cube.rotateFrontClockwise();
    cube.rotateFrontCounterClockwise();
    cube.rotateRightClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateLeftClockwise();
    cube.rotateLeftCounterClockwise();
    cube.rotateDownClockwise();
    cube.rotateDownCounterClockwise();
    cube.rotateBackClockwise();
    cube.rotateBackCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 23. ���� ����������� ���������
TEST(RubiksCubeTest, AlternatingMoves) {
    RubiksCube cube;

    for (int i = 0; i < 6; i++) {
        cube.rotateFrontClockwise();
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 24. ���� ��������� �����������
TEST(RubiksCubeTest, ReverseAlternatingMoves) {
    RubiksCube cube;

    for (int i = 0; i < 6; i++) {
        cube.rotateFrontCounterClockwise();
        cube.rotateRightCounterClockwise();
        cube.rotateUpCounterClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 25. ���� �������� ��������� ����� reset
TEST(RubiksCubeTest, StateAfterReset) {
    RubiksCube cube;

    cube.scramble(100);
    bool scrambled = cube.isSolved();

    cube.initialize();
    bool reset = cube.isSolved();

    EXPECT_FALSE(scrambled);
    EXPECT_TRUE(reset);
}

// 26. ���� ������������������ ��� �������� �����������
TEST(RubiksCubeTest, IntegrityCheckSequence) {
    RubiksCube cube;

    // ��� ���� F R U B L D
    for (int i = 0; i < 3; i++) {
        cube.rotateFrontClockwise();
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
        cube.rotateBackClockwise();
        cube.rotateLeftClockwise();
        cube.rotateDownClockwise();
    }

    EXPECT_FALSE(cube.isSolved());

    // ��� ���� �������� ������������������
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

// 27. ���� �������������� �������������
TEST(RubiksCubeTest, ExtremeScrambling) {
    RubiksCube cube;

    cube.scramble(1000);
    EXPECT_FALSE(cube.isSolved());

    // ���������, ��� ����� �������������� ������������� ����� ��������
    cube.initialize();
    EXPECT_TRUE(cube.isSolved());
}

// 28. ���� ���������� ��� �������� ���� ������
TEST(RubiksCubeTest, AllFacesCombination) {
    RubiksCube cube;

    cube.rotateFrontClockwise();
    cube.rotateFrontClockwise();
    cube.rotateRightClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateUpClockwise();
    cube.rotateBackClockwise();
    cube.rotateBackClockwise();
    cube.rotateLeftClockwise();
    cube.rotateLeftClockwise();
    cube.rotateDownClockwise();
    cube.rotateDownClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 29. ���� �� ������������ ���� �������������������
TEST(RubiksCubeTest, SequenceEquivalence) {
    RubiksCube cube1, cube2;

    // ���������� ������������������
    cube1.rotateFrontClockwise();
    cube1.rotateRightClockwise();

    cube2.rotateFrontClockwise();
    cube2.rotateRightClockwise();

    // ���� ������ ���� � ���������� ���������
    EXPECT_EQ(cube1.isSolved(), cube2.isSolved());
}

// 30. ���� ��������� ��������
TEST(RubiksCubeTest, InverseOperations) {
    RubiksCube cube;

    // ��������� ��������
    cube.rotateFrontClockwise();
    cube.rotateRightClockwise();
    cube.rotateUpClockwise();
    cube.rotateBackClockwise();

    EXPECT_FALSE(cube.isSolved());

    // ��������� �������� �������� � �������� �������
    cube.rotateBackCounterClockwise();
    cube.rotateUpCounterClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateFrontCounterClockwise();

    EXPECT_TRUE(cube.isSolved());
}

// 31. ���� ������������������
TEST(RubiksCubeTest, PerformanceTest) {
    RubiksCube cube;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; i++) {
        cube.rotateFrontClockwise();
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // ���������, ��� ���������� ������ �������� ����� (����� 1 �������)
    EXPECT_LT(duration.count(), 1000);
}

// 32. ���� ������������������� �������������
TEST(RubiksCubeTest, ScrambleDeterminism) {
    RubiksCube cube1, cube2;

    // ������������ � ���������� ����������� �����
    cube1.scramble(20);
    cube2.scramble(20);

    // ���� ������ ���� � ������ ���������� (��-�� �����������),
    // �� ��� �� ������ ���� ������
    EXPECT_FALSE(cube1.isSolved());
    EXPECT_FALSE(cube2.isSolved());
}

// 33. ���� ������� ������� ����
TEST(RubiksCubeTest, BasicCubeProperties) {
    RubiksCube cube;

    // ����� ������������� ��� ������ ���� �����
    EXPECT_TRUE(cube.isSolved());

    // ����� ��������� ��� ������ �������� ��������� ���������
    cube.rotateFrontClockwise();
    EXPECT_FALSE(cube.isSolved());

    cube.initialize();
    cube.rotateRightClockwise();
    EXPECT_FALSE(cube.isSolved());
}

// 34. ���� ���������� � �������������� ������
TEST(RubiksCubeTest, RepeatedMovesCombination) {
    RubiksCube cube;

    // F F F F = identity
    for (int i = 0; i < 4; i++) {
        cube.rotateFrontClockwise();
    }
    EXPECT_TRUE(cube.isSolved());

    // R R R R = identity
    for (int i = 0; i < 4; i++) {
        cube.rotateRightClockwise();
    }
    EXPECT_TRUE(cube.isSolved());

    // U U U U = identity
    for (int i = 0; i < 4; i++) {
        cube.rotateUpClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 35. ���� ������� ����������������� ������������������
TEST(RubiksCubeTest, ComplexRecoverySequence) {
    RubiksCube cube;

    // ��������� ������������������
    cube.rotateFrontClockwise();
    cube.rotateRightCounterClockwise();
    cube.rotateUpClockwise();
    cube.rotateBackCounterClockwise();
    cube.rotateLeftClockwise();
    cube.rotateDownCounterClockwise();
    cube.rotateFrontCounterClockwise();
    cube.rotateRightClockwise();

    EXPECT_FALSE(cube.isSolved());

    // �������� ������������������ ��� ��������������
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