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

// 31. Тест методов colorToChar через отображение
TEST(RubiksCubeTest, ColorToCharCoverage) {
    RubiksCube cube;

    // Захватываем вывод display и анализируем символы
    testing::internal::CaptureStdout();
    cube.display();
    string output = testing::internal::GetCapturedStdout();

    // Проверяем что в выводе присутствуют ожидаемые символы цветов
    EXPECT_TRUE(output.find('R') != string::npos); // RED
    EXPECT_TRUE(output.find('O') != string::npos); // ORANGE  
    EXPECT_TRUE(output.find('G') != string::npos); // GREEN
    EXPECT_TRUE(output.find('B') != string::npos); // BLUE
    EXPECT_TRUE(output.find('W') != string::npos); // WHITE
    EXPECT_TRUE(output.find('Y') != string::npos); // YELLOW
}

// 32. Тест методов отображения (printRow, printFace, display)
TEST(RubiksCubeTest, DisplayMethodsCoverage) {
    RubiksCube cube;

    // Тестируем что методы не падают при вызове
    testing::internal::CaptureStdout();
    cube.display();
    string displayOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(displayOutput.empty());

    // Проверяем структуру вывода
    EXPECT_TRUE(displayOutput.find("Rubiks Cube") != string::npos);
    EXPECT_TRUE(displayOutput.find("U(white)") != string::npos);
    EXPECT_TRUE(displayOutput.find("D(yellow)") != string::npos);
    EXPECT_TRUE(displayOutput.find("Center:") != string::npos);
}

// 33. Тест isFaceUniform через публичное поведение
TEST(RubiksCubeTest, IsFaceUniformCoverage) {
    RubiksCube cube;

    // В начальном состоянии все грани равномерны
    EXPECT_TRUE(cube.isSolved());

    // После одного хода грань может остаться равномерной, но куб не собран
    cube.rotateFrontClockwise();
    // Не можем напрямую проверить isFaceUniform, но проверяем косвенно
    bool frontUniformAfterRotation = cube.isSolved(); // Должно быть false
    EXPECT_FALSE(frontUniformAfterRotation);
}

// 34. Тест всех 12 случаев вращения в scramble
TEST(RubiksCubeTest, CompleteScrambleCoverage) {
    // Тестируем что все варианты из scramble работают
    for (int attempt = 0; attempt < 50; attempt++) {
        RubiksCube cube;
        cube.scramble(20); // Большое количество ходов для покрытия всех случаев
        EXPECT_FALSE(cube.isSolved());
    }
}

// 35. Тест методов вращения граней через их эффекты
TEST(RubiksCubeTest, FaceRotationMethodsCoverage) {
    RubiksCube cube;

    // rotateFaceClockwise и rotateFaceCounterClockwise вызываются из публичных методов
    // Проверяем их работу через публичный интерфейс

    // Тест 4-х кратного вращения (должно вернуть в исходное состояние)
    for (int i = 0; i < 4; i++) {
        cube.rotateFrontClockwise();
    }
    EXPECT_TRUE(cube.isSolved());

    for (int i = 0; i < 4; i++) {
        cube.rotateFrontCounterClockwise();
    }
    EXPECT_TRUE(cube.isSolved());
}

// 36. Тест граничных значений для scramble
TEST(RubiksCubeTest, ScrambleBoundaryValues) {
    RubiksCube cube1, cube2, cube3;

    cube1.scramble(0);  // 0 ходов - куб должен остаться собранным
    EXPECT_TRUE(cube1.isSolved());

    cube2.scramble(1);  // 1 ход - куб не собран
    EXPECT_FALSE(cube2.isSolved());

    cube3.scramble(1000); // Много ходов - куб не собран
    EXPECT_FALSE(cube3.isSolved());
}

// 37. Тест повторной инициализации после сложных операций
TEST(RubiksCubeTest, ReinitializationAfterComplexOperations) {
    RubiksCube cube;

    // Выполняем сложную последовательность
    for (int i = 0; i < 10; i++) {
        cube.rotateFrontClockwise();
        cube.rotateRightClockwise();
        cube.rotateUpClockwise();
        cube.rotateBackClockwise();
        cube.rotateLeftClockwise();
        cube.rotateDownClockwise();
    }

    EXPECT_FALSE(cube.isSolved());

    // Инициализация должна вернуть в исходное состояние
    cube.initialize();
    EXPECT_TRUE(cube.isSolved());
}

// 38. Тест комбинаций с проверкой симметрии
TEST(RubiksCubeTest, SymmetricCombinationCoverage) {
    RubiksCube cube;

    // Последовательность и обратная последовательность
    vector<function<void(RubiksCube&)>> forwardMoves = {
        [](RubiksCube& c) { c.rotateFrontClockwise(); },
        [](RubiksCube& c) { c.rotateRightClockwise(); },
        [](RubiksCube& c) { c.rotateUpClockwise(); },
        [](RubiksCube& c) { c.rotateBackClockwise(); }
    };

    vector<function<void(RubiksCube&)>> backwardMoves = {
        [](RubiksCube& c) { c.rotateBackCounterClockwise(); },
        [](RubiksCube& c) { c.rotateUpCounterClockwise(); },
        [](RubiksCube& c) { c.rotateRightCounterClockwise(); },
        [](RubiksCube& c) { c.rotateFrontCounterClockwise(); }
    };

    // Применяем прямую последовательность
    for (auto& move : forwardMoves) {
        move(cube);
    }
    EXPECT_FALSE(cube.isSolved());

    // Применяем обратную последовательность
    for (auto& move : backwardMoves) {
        move(cube);
    }
    EXPECT_TRUE(cube.isSolved());
}

// 39. Тест производительности и стабильности
TEST(RubiksCubeTest, PerformanceAndStability) {
    RubiksCube cube;

    // Многократные операции для покрытия всех веток кода
    for (int i = 0; i < 100; i++) {
        cube.rotateFrontClockwise();
        cube.rotateRightCounterClockwise();
        cube.rotateUpClockwise();
        cube.rotateDownCounterClockwise();
        cube.rotateLeftClockwise();
        cube.rotateBackCounterClockwise();
    }

    // После многих операций куб не должен быть собран
    EXPECT_FALSE(cube.isSolved());

    // Но инициализация должна работать стабильно
    cube.initialize();
    EXPECT_TRUE(cube.isSolved());
}

// 40. Тест детерминированности scramble
TEST(RubiksCubeTest, ScrambleDeterminism) {
    RubiksCube cube1, cube2;

    // Два одинаковых scramble с разными сидами должны дать разные результаты
    cube1.scramble(10);
    cube2.scramble(10);

    // Проверяем что оба куба не собраны
    EXPECT_FALSE(cube1.isSolved());
    EXPECT_FALSE(cube2.isSolved());

    // Проверяем что reset работает для обоих
    cube1.initialize();
    cube2.initialize();
    EXPECT_TRUE(cube1.isSolved());
    EXPECT_TRUE(cube2.isSolved());
}

// 41. Тест комплексной проверки всех методов вращения
TEST(RubiksCubeTest, ComprehensiveRotationTest) {
    RubiksCube cube;

    // Тестируем все 12 методов вращения по отдельности
    cube.rotateFrontClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateFrontCounterClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateRightClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateRightCounterClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateLeftClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateLeftCounterClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateUpClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateUpCounterClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateDownClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateDownCounterClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateBackClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();

    cube.rotateBackCounterClockwise();
    EXPECT_FALSE(cube.isSolved());
    cube.initialize();
}

// 42. Тест вывода на разных состояниях куба
TEST(RubiksCubeTest, DisplayOnDifferentStates) {
    RubiksCube cube1, cube2, cube3;

    // Display на собранном кубе
    testing::internal::CaptureStdout();
    cube1.display();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output1.empty());

    // Display после одного хода
    cube2.rotateFrontClockwise();
    testing::internal::CaptureStdout();
    cube2.display();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output2.empty());

    // Display после scramble
    cube3.scramble(5);
    testing::internal::CaptureStdout();
    cube3.display();
    string output3 = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output3.empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
