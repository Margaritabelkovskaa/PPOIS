#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include "BubbleSort.h"
#include "Employee.h"

// Базовые тесты для vector<int>
TEST(BubbleSortTest, EmptyVector) {
    std::vector<int> empty;
    BubbleSort<int>::sort(empty);
    EXPECT_TRUE(empty.empty());
}

TEST(BubbleSortTest, SingleElement) {
    std::vector<int> single = { 42 };
    BubbleSort<int>::sort(single);
    EXPECT_EQ(1, single.size());
    EXPECT_EQ(42, single[0]);
}

TEST(BubbleSortTest, AlreadySortedInt) {
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    BubbleSort<int>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(BubbleSortTest, ReverseSortedInt) {
    std::vector<int> data = { 5, 4, 3, 2, 1 };
    BubbleSort<int>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(BubbleSortTest, RandomOrderInt) {
    std::vector<int> data = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    BubbleSort<int>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

// Тесты для vector<string>
TEST(BubbleSortTest, AlreadySortedString) {
    std::vector<std::string> data = { "apple", "banana", "cherry", "date" };
    BubbleSort<std::string>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(BubbleSortTest, ReverseSortedString) {
    std::vector<std::string> data = { "date", "cherry", "banana", "apple" };
    BubbleSort<std::string>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

// Тесты для пользовательского класса Employee
TEST(BubbleSortTest, EmployeeClass) {
    std::vector<Employee> data = {
        Employee("Bob", 30, 3500.0),
        Employee("Alice", 25, 2500.0),
        Employee("Charlie", 22, 4200.0)
    };
    BubbleSort<Employee>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
    EXPECT_EQ(2500.0, data[0].getSalary());
    EXPECT_EQ(3500.0, data[1].getSalary());
    EXPECT_EQ(4200.0, data[2].getSalary());
}

TEST(BubbleSortTest, EmployeeClassReverse) {
    std::vector<Employee> data = {
        Employee("Charlie", 22, 4500.0),
        Employee("Bob", 30, 2800.0),
        Employee("Alice", 25, 1500.0)
    };
    BubbleSort<Employee>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

// Тесты для массивов (T*)
TEST(BubbleSortTest, IntArray) {
    int arr[] = { 5, 2, 8, 1, 9, 3 };
    const size_t size = sizeof(arr) / sizeof(arr[0]);

    BubbleSort<int>::sort(arr, size);
    EXPECT_TRUE(std::is_sorted(arr, arr + size));
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(9, arr[size - 1]);
}

TEST(BubbleSortTest, EmployeeArray) {
    Employee arr[] = {
        Employee("David", 40, 5000.0),
        Employee("Eva", 35, 1200.0),
        Employee("Frank", 28, 3800.0)
    };
    const size_t size = sizeof(arr) / sizeof(arr[0]);

    BubbleSort<Employee>::sort(arr, size);
    EXPECT_TRUE(std::is_sorted(arr, arr + size));
    EXPECT_EQ(1200.0, arr[0].getSalary());
    EXPECT_EQ(5000.0, arr[size - 1].getSalary());
}

// Тест на эффективность (ранняя остановка при отсортированном массиве)
TEST(BubbleSortTest, EarlyTermination) {
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    // Счетчик для отслеживания количества проходов можно добавить в класс
    // Но для простоты тестируем, что массив остался отсортированным
    BubbleSort<int>::sort(data);
    EXPECT_EQ(std::vector<int>({1, 2, 3, 4, 5}), data);
}

// Главная функция
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
