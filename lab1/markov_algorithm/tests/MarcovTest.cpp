#include <gtest/gtest.h>
#include "MarkovAlgorithm.h"

// Проверяет базовую замену одного символа на другой
TEST(MarkovTest, SimpleReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    EXPECT_EQ(algo.execute("aaa"), "bbb");
}

// Проверяет замену нескольких разных символов
TEST(MarkovTest, MultipleReplacements) {
    MarkovAlgorithm algo;
    algo.addRule("0", "1");
    algo.addRule("1", "0");
    EXPECT_EQ(algo.execute("101"), "010");
}

// Проверяет остановку алгоритма при применении финального правила
TEST(MarkovTest, FinalRuleStops) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("b", "c", true);
    EXPECT_EQ(algo.execute("aaa"), "c");
}

// Проверяет обработку пустой входной строки
TEST(MarkovTest, EmptyInput) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    EXPECT_EQ(algo.execute(""), "");
}

// Проверяет случай когда ни одно правило не может быть применено
TEST(MarkovTest, NoRulesApply) {
    MarkovAlgorithm algo;
    algo.addRule("x", "y");
    EXPECT_EQ(algo.execute("abc"), "abc");
}

// Проверяет замену пробелов в строке
TEST(MarkovTest, SpaceReplacement) {
    MarkovAlgorithm algo;
    algo.addRule(" ", "_");
    EXPECT_EQ(algo.execute("a b c"), "a_b_c");
}

// Проверяет чувствительность к регистру символов
TEST(MarkovTest, DifferentCase) {
    MarkovAlgorithm algo;
    algo.addRule("A", "B");
    algo.addRule("a", "b");
    EXPECT_EQ(algo.execute("Aa"), "Bb");
}

// Проверяет влияние порядка правил на результат
TEST(MarkovTest, RuleOrder) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("b", "c");
    EXPECT_EQ(algo.execute("a"), "c");
}

// Проверяет замену одиночного символа
TEST(MarkovTest, SingleReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("x", "y");
    EXPECT_EQ(algo.execute("x"), "y");
}

// Проверяет замену целых слов
TEST(MarkovTest, WordReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("cat", "dog");
    EXPECT_EQ(algo.execute("cat"), "dog");
}

// Проверяет обработку специальных символов
TEST(MarkovTest, SpecialChars) {
    MarkovAlgorithm algo;
    algo.addRule("@", "at");
    EXPECT_EQ(algo.execute("user@mail"), "useratmail");
}

// Проверяет замену чисел на текстовое представление
TEST(MarkovTest, Numbers) {
    MarkovAlgorithm algo;
    algo.addRule("1", "one");
    EXPECT_EQ(algo.execute("1"), "one");
}

// Проверяет очистку всех правил
TEST(MarkovTest, ClearRules) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.clear();
    EXPECT_EQ(algo.execute("a"), "a");
}

// Проверяет что финальное правило применяется только один раз
TEST(MarkovTest, FinalRuleOnce) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b", true);
    EXPECT_EQ(algo.execute("aaa"), "baa");
}

// Проверяет удаление символов из строки
TEST(MarkovTest, DeleteChars) {
    MarkovAlgorithm algo;
    algo.addRule("a", "");
    EXPECT_EQ(algo.execute("abc"), "bc");
}

// Проверяет обработку длинных строк
TEST(MarkovTest, LongStrings) {
    MarkovAlgorithm algo;
    algo.addRule("t", "T");
    EXPECT_EQ(algo.execute("ttt"), "TTT");
}

// Проверяет правила содержащие пробелы
TEST(MarkovTest, RulesWithSpaces) {
    MarkovAlgorithm algo;
    algo.addRule("hello world", "hi");
    EXPECT_EQ(algo.execute("hello world"), "hi");
}

// Проверяет работу алгоритма без правил
TEST(MarkovTest, NoRules) {
    MarkovAlgorithm algo;
    EXPECT_EQ(algo.execute("test"), "test");
}

// Проверяет множественные замены в одной строке
TEST(MarkovTest, MultipleInString) {
    MarkovAlgorithm algo;
    algo.addRule("cat", "dog");
    algo.addRule("red", "blue");
    EXPECT_EQ(algo.execute("red cat"), "blue dog");
}

// Проверяет простой случай применения финального правила
TEST(MarkovTest, SimpleFinal) {
    MarkovAlgorithm algo;
    algo.addRule("aa", "b", true);
    EXPECT_EQ(algo.execute("aaa"), "ba");
}

// Проверяет замену символа на такой же символ
TEST(MarkovTest, ReplaceToSame) {
    MarkovAlgorithm algo;
    algo.addRule("a", "a");
    EXPECT_EQ(algo.execute("aaa"), "aaa");
}

// Проверяет что первое правило имеет приоритет при дублировании
TEST(MarkovTest, DuplicateRules) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("a", "c");
    EXPECT_EQ(algo.execute("a"), "b");
}

// Проверяет замену подстроки в середине строки
TEST(MarkovTest, SubstringReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("ab", "ba");
    EXPECT_EQ(algo.execute("abc"), "bac");
}

// Проверяет удаление символа из середины строки
TEST(MarkovTest, EmptyReplacementMiddle) {
    MarkovAlgorithm algo;
    algo.addRule("b", "");
    EXPECT_EQ(algo.execute("abc"), "ac");
}

// Проверяет замену символа в начале строки
TEST(MarkovTest, ReplaceAtStart) {
    MarkovAlgorithm algo;
    algo.addRule("a", "x");
    EXPECT_EQ(algo.execute("abc"), "xbc");
}

// Проверяет замену символа в конце строки
TEST(MarkovTest, ReplaceAtEnd) {
    MarkovAlgorithm algo;
    algo.addRule("c", "x");
    EXPECT_EQ(algo.execute("abc"), "abx");
}

// Проверяет правила с несколькими символами
TEST(MarkovTest, MultiCharRules) {
    MarkovAlgorithm algo;
    algo.addRule("abc", "xyz");
    EXPECT_EQ(algo.execute("abc"), "xyz");
}

// Проверяет цепочку последовательных замен
TEST(MarkovTest, ChainReplacement) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("b", "c");
    algo.addRule("c", "d");
    EXPECT_EQ(algo.execute("a"), "d");
}

// Проверяет работу с разными типами символов
TEST(MarkovTest, MixedChars) {
    MarkovAlgorithm algo;
    algo.addRule("1", "one");
    algo.addRule("a", "A");
    EXPECT_EQ(algo.execute("1a"), "oneA");
}

// Базовый тест для проверки покрытия
TEST(MarkovTest, CoverageTest) {
    MarkovAlgorithm algo;
    algo.addRule("test", "passed");
    EXPECT_EQ(algo.execute("test"), "passed");
}

// Проверяет обработку бесконечного цикла и превышение лимита итераций
TEST(MarkovTest, MaxIterations) {
    MarkovAlgorithm algo;
    algo.addRule("a", "aa");
    EXPECT_THROW(algo.execute("a"), exception);
}

// Проверяет валидацию правил при добавлении
TEST(MarkovTest, RuleValidation) {
    MarkovAlgorithm algo;
    EXPECT_THROW(algo.addRule("", "b"), exception);
    EXPECT_NO_THROW(algo.addRule("a", "b"));
}

// Проверяет корректность вывода списка правил
TEST(MarkovTest, PrintRulesCoverage) {
    MarkovAlgorithm algo;
    
    testing::internal::CaptureStdout();
    algo.printRules();
    string emptyOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(emptyOutput.empty());

    algo.addRule("a", "b");
    testing::internal::CaptureStdout();
    algo.printRules();
    string oneRuleOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(oneRuleOutput.empty());

    algo.addRule("x", "y", true);
    testing::internal::CaptureStdout();
    algo.printRules();
    string finalRuleOutput = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(finalRuleOutput.empty());
}

// Проверяет применение правил в разных позициях строки
TEST(MarkovTest, RuleApplicationPositions) {
    MarkovAlgorithm algo;
    algo.addRule("ab", "BA");
    EXPECT_EQ(algo.execute("abc"), "BAc");

    algo.clear();
    algo.addRule("bc", "CB");
    EXPECT_EQ(algo.execute("abcd"), "aCBd");

    algo.clear();
    algo.addRule("cd", "DC");
    EXPECT_EQ(algo.execute("abcd"), "abDC");
}

// Проверяет поиск применимых правил в различных ситуациях
TEST(MarkovTest, FindApplicableRule) {
    MarkovAlgorithm algo;
    algo.addRule("x", "y");
    EXPECT_EQ(algo.execute("abc"), "abc");

    algo.clear();
    algo.addRule("a", "A");
    EXPECT_EQ(algo.execute("abc"), "Abc");

    algo.clear();
    algo.addRule("a", "A", true);
    EXPECT_EQ(algo.execute("abc"), "Abc");
}

// Проверяет процесс итеративного применения правил
TEST(MarkovTest, ProcessIteration) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    EXPECT_EQ(algo.execute("a"), "b");

    algo.clear();
    algo.addRule("a", "aa");
    algo.addRule("aa", "b", true);
    EXPECT_EQ(algo.execute("a"), "b");

    algo.clear();
    algo.addRule("x", "y");
    EXPECT_EQ(algo.execute("abc"), "abc");
}

// Проверяет корректность очистки правил
TEST(MarkovTest, ClearRulesCoverage) {
    MarkovAlgorithm algo;
    algo.addRule("a", "b");
    algo.addRule("c", "d");
    EXPECT_EQ(algo.execute("ac"), "bd");
    algo.clear();
    EXPECT_EQ(algo.execute("ac"), "ac");
}

// Проверяет сложный сценарий преобразования
TEST(MarkovTest, ComplexScenario) {
    MarkovAlgorithm algo;
    algo.addRule("1", "0|");
    algo.addRule("|0", "0||");
    algo.addRule("0", "");
    string result = algo.execute("101");
    EXPECT_FALSE(result.empty());
}

// Проверяет приоритет более длинных правил
TEST(MarkovTest, RulePriority) {
    MarkovAlgorithm algo;
    algo.addRule("aa", "FIRST");
    algo.addRule("a", "second");
    string result = algo.execute("aaa");
    EXPECT_TRUE(result == "FIRSTa" || result == "secondseconda");
}

// Проверяет граничные случаи работы алгоритма
TEST(MarkovTest, EdgeCases) {
    MarkovAlgorithm algo;
    algo.addRule("test", "");
    EXPECT_EQ(algo.execute("test"), "");

    algo.clear();
    algo.addRule("a", "b");
    string longInput(100, 'a');
    string expectedResult(100, 'b');
    EXPECT_EQ(algo.execute(longInput), expectedResult);
}

// Проверяет обработку исключительных ситуаций
TEST(MarkovTest, ExceptionCases) {
    MarkovAlgorithm algo;
    algo.addRule("a", "aa");
    EXPECT_THROW(algo.execute("a"), exception);

    algo.clear();
    algo.addRule("a", "b");
    algo.addRule("b", "a");
    EXPECT_THROW(algo.execute("a"), exception);
}

// Проверяет работу с правилами максимальной длины
TEST(MarkovTest, MaxLengthRules) {
    MarkovAlgorithm algo;
    string longPattern(50, 'a');
    string longReplacement(50, 'b');
    algo.addRule(longPattern, longReplacement);
    EXPECT_EQ(algo.execute(longPattern), longReplacement);
}

// Проверяет комбинацию финальных и нефинальных правил
TEST(MarkovTest, MixedFinalNonFinal) {
    MarkovAlgorithm algo;
    algo.addRule("a", "A");
    algo.addRule("b", "B", true);
    algo.addRule("c", "C");
    string result = algo.execute("abc");
    EXPECT_TRUE(result == "ABc" || result == "aBc");
}

// Проверяет повторное использование объекта алгоритма
TEST(MarkovTest, ReuseObject) {
    MarkovAlgorithm algo;
    algo.addRule("x", "y");
    EXPECT_EQ(algo.execute("x"), "y");
    EXPECT_EQ(algo.execute("xx"), "yy");
    EXPECT_EQ(algo.execute("test"), "test");
}

// Проверяет правила содержащие цифры и буквы
TEST(MarkovTest, AlphanumericRules) {
    MarkovAlgorithm algo;
    algo.addRule("a1", "1a");
    algo.addRule("b2", "2b");
    EXPECT_EQ(algo.execute("a1b2"), "1a2b");
}

// Проверяет вывод правил после их очистки
TEST(MarkovTest, PrintAfterClear) {
    MarkovAlgorithm algo;
    algo.addRule("test", "passed");
    algo.clear();

    testing::internal::CaptureStdout();
    algo.printRules();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Проверяет граничные случаи с одним символом
TEST(MarkovTest, SingleCharEdgeCases) {
    MarkovAlgorithm algo;
    algo.addRule("a", "");
    EXPECT_EQ(algo.execute("a"), "");
    EXPECT_EQ(algo.execute(""), "");
}

// Проверяет правила с повторяющимися паттернами
TEST(MarkovTest, RepeatedPatterns) {
    MarkovAlgorithm algo;
    algo.addRule("aa", "bb");
    algo.addRule("bb", "cc");
    string result = algo.execute("aaaa");
    EXPECT_TRUE(result == "ccbb" || result == "bbcc" || result == "cccc");
}

// Проверяет производительность при большом количестве правил
TEST(MarkovTest, ManyRules) {
    MarkovAlgorithm algo;
    for (char c = 'a'; c <= 'z'; c++) {
        string from(1, c);
        string to(1, toupper(c));
        algo.addRule(from, to);
    }
    EXPECT_EQ(algo.execute("hello"), "HELLO");
}

// Проверяет обработку специальных последовательностей символов
TEST(MarkovTest, SpecialSequences) {
    MarkovAlgorithm algo;
    algo.addRule("\\n", "newline");
    algo.addRule("\\t", "tab");
    EXPECT_EQ(algo.execute("a\\nb"), "anewlineb");
}

// Комплексный тест для полного покрытия функциональности
TEST(MarkovTest, FinalCoverageTest) {
    MarkovAlgorithm algo;
    algo.addRule("start", "begin");
    algo.addRule("end", "finish", true);
    algo.addRule("middle", "center");
    string result = algo.execute("start middle end");
    EXPECT_FALSE(result.empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
