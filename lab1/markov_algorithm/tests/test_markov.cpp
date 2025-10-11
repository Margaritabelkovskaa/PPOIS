#include <gtest/gtest.h>
#include "markov_algorithm.h"

// 1. Простая замена одного символа
TEST(MarkovTest, SimpleReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    EXPECT_EQ(algo.execute("aaa"), "bbb");
}

// 2. Замена нескольких символов
TEST(MarkovTest, MultipleReplacements) {
    MarkovAlgorithm algo;
    algo.addRule("0", "1");
    algo.addRule("1", "0");
    EXPECT_EQ(algo.execute("101"), "010");
}

// 3. Финальное правило останавливает выполнение
TEST(MarkovTest, FinalRuleStops) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("b", "c", true);
    EXPECT_EQ(algo.execute("aaa"), "c");
}

// 4. Пустая строка
TEST(MarkovTest, EmptyInput) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    EXPECT_EQ(algo.execute(""), "");
}

// 5. Нет подходящих правил
TEST(MarkovTest, NoRulesApply) {
    MarkovAlgorithm algo;
    algo.addRule("x", "y");
    EXPECT_EQ(algo.execute("abc"), "abc");
}

// 6. Замена пробелов
TEST(MarkovTest, SpaceReplacement) {
    MarkovAlgorithm algo;
    algo.addRule(" ", "_");
    EXPECT_EQ(algo.execute("a b c"), "a_b_c");
}

// 7. Разный регистр
TEST(MarkovTest, DifferentCase) {
    MarkovAlgorithm algo;
    algo.addRule("A", "B");
    algo.addRule("a", "b");
    EXPECT_EQ(algo.execute("Aa"), "Bb");
}

// 8. Порядок правил имеет значение
TEST(MarkovTest, RuleOrder) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("b", "c");
    EXPECT_EQ(algo.execute("a"), "c");
}

// 9. Одиночная замена
TEST(MarkovTest, SingleReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("x", "y");
    EXPECT_EQ(algo.execute("x"), "y");
}

// 10. Замена слов
TEST(MarkovTest, WordReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("cat", "dog");
    EXPECT_EQ(algo.execute("cat"), "dog");
}

// 11. Спецсимволы
TEST(MarkovTest, SpecialChars) {
    MarkovAlgorithm algo;
    algo.addRule("@", "at");
    EXPECT_EQ(algo.execute("user@mail"), "useratmail");
}

// 12. Числа
TEST(MarkovTest, Numbers) {
    MarkovAlgorithm algo;
    algo.addRule("1", "one");
    EXPECT_EQ(algo.execute("1"), "one");
}

// 13. Очистка правил
TEST(MarkovTest, ClearRules) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.clear();
    EXPECT_EQ(algo.execute("a"), "a");
}

// 14. Финальное правило применяется один раз
TEST(MarkovTest, FinalRuleOnce) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b", true);
    EXPECT_EQ(algo.execute("aaa"), "baa");
}

// 15. Удаление символов
TEST(MarkovTest, DeleteChars) {
    MarkovAlgorithm algo;
    algo.addRule("a", "");
    EXPECT_EQ(algo.execute("abc"), "bc");
}

// 16. Длинные строки
TEST(MarkovTest, LongStrings) {
    MarkovAlgorithm algo;
    algo.addRule("t", "T");
    EXPECT_EQ(algo.execute("ttt"), "TTT");
}

// 17. Правила с пробелами
TEST(MarkovTest, RulesWithSpaces) {
    MarkovAlgorithm algo;
    algo.addRule("hello world", "hi");
    EXPECT_EQ(algo.execute("hello world"), "hi");
}

// 18. Без правил
TEST(MarkovTest, NoRules) {
    MarkovAlgorithm algo;
    EXPECT_EQ(algo.execute("test"), "test");
}

// 19. Множественные замены в строке
TEST(MarkovTest, MultipleInString) {
    MarkovAlgorithm algo;
    algo.addRule("cat", "dog");
    algo.addRule("red", "blue");
    EXPECT_EQ(algo.execute("red cat"), "blue dog");
}

// 20. Простой финальный случай
TEST(MarkovTest, SimpleFinal) {
    MarkovAlgorithm algo;
    algo.addRule("aa", "b", true);
    EXPECT_EQ(algo.execute("aaa"), "ba");
}

// 21. Замена на такой же символ
TEST(MarkovTest, ReplaceToSame) {
    MarkovAlgorithm algo;
    algo.addRule("a", "a");
    EXPECT_EQ(algo.execute("aaa"), "aaa");
}

// 22. Несколько одинаковых правил
TEST(MarkovTest, DuplicateRules) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("a", "c"); // второе правило никогда не применится
    EXPECT_EQ(algo.execute("a"), "b");
}

// 23. Замена подстроки
TEST(MarkovTest, SubstringReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("ab", "ba");
    EXPECT_EQ(algo.execute("abc"), "bac");
}

// 24. Пустая замена в середине
TEST(MarkovTest, EmptyReplacementMiddle) {
    MarkovAlgorithm algo;
    algo.addRule("b", "");
    EXPECT_EQ(algo.execute("abc"), "ac");
}

// 25. Замена в начале строки
TEST(MarkovTest, ReplaceAtStart) {
    MarkovAlgorithm algo;
    algo.addRule("a", "x");
    EXPECT_EQ(algo.execute("abc"), "xbc");
}

// 26. Замена в конце строки
TEST(MarkovTest, ReplaceAtEnd) {
    MarkovAlgorithm algo;
    algo.addRule("c", "x");
    EXPECT_EQ(algo.execute("abc"), "abx");
}

// 27. Многобуквенные правила
TEST(MarkovTest, MultiCharRules) {
    MarkovAlgorithm algo;
    algo.addRule("abc", "xyz");
    EXPECT_EQ(algo.execute("abc"), "xyz");
}

// 28. Цепочка замен
TEST(MarkovTest, ChainReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("b", "c");
    algo.addRule("c", "d");
    EXPECT_EQ(algo.execute("a"), "d");
}

// 29. Смешанные символы
TEST(MarkovTest, MixedChars) {
    MarkovAlgorithm algo;
    algo.addRule("1", "one");
    algo.addRule("a", "A");
    EXPECT_EQ(algo.execute("1a"), "oneA");
}

// 30. Простой тест на покрытие
TEST(MarkovTest, CoverageTest) {
    MarkovAlgorithm algo;
    algo.addRule("test", "passed");
    EXPECT_EQ(algo.execute("test"), "passed");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}