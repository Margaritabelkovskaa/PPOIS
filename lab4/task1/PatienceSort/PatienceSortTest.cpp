#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include "PatienceSort.h"
#include "Employee.h"

TEST(PatienceSortTest, EmployeeClass) {
    std::vector<Employee> data = {
        Employee("Bob", 30, 3500.0),
        Employee("Alice", 25, 2500.0),
        Employee("Charlie", 22, 4200.0)
    };
    PatienceSort<Employee>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
    EXPECT_EQ(2500.0, data[0].getSalary());
    EXPECT_EQ(3500.0, data[1].getSalary());
    EXPECT_EQ(4200.0, data[2].getSalary());
}

TEST(PatienceSortTest, EmployeeClassAlreadySorted) {
    std::vector<Employee> data = {
        Employee("Alice", 25, 1800.0),
        Employee("Bob", 30, 3200.0),
        Employee("Charlie", 22, 4800.0)
    };
    PatienceSort<Employee>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(PatienceSortTest, EmployeeClassReverse) {
    std::vector<Employee> data = {
        Employee("Charlie", 22, 4500.0),
        Employee("Bob", 30, 2800.0),
        Employee("Alice", 25, 1500.0)
    };
    PatienceSort<Employee>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(PatienceSortTest, EmployeeArray) {
    Employee arr[] = {
        Employee("David", 40, 5000.0),
        Employee("Eva", 35, 1200.0),
        Employee("Frank", 28, 3800.0)
    };
    const size_t size = sizeof(arr) / sizeof(arr[0]);

    PatienceSort<Employee>::sort(arr, size);
    EXPECT_TRUE(std::is_sorted(arr, arr + size));
    EXPECT_EQ(1200.0, arr[0].getSalary());
    EXPECT_EQ(5000.0, arr[size - 1].getSalary());
}

// Тесты для vector<int>
TEST(PatienceSortTest, EmptyVector) {
    std::vector<int> empty;
    PatienceSort<int>::sort(empty);
    EXPECT_TRUE(empty.empty());
}

TEST(PatienceSortTest, SingleElement) {
    std::vector<int> single = {42};
    PatienceSort<int>::sort(single);
    EXPECT_EQ(1, single.size());
    EXPECT_EQ(42, single[0]);
}

TEST(PatienceSortTest, AlreadySortedInt) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    PatienceSort<int>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(PatienceSortTest, ReverseSortedInt) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    PatienceSort<int>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(PatienceSortTest, RandomOrderInt) {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    PatienceSort<int>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(PatienceSortTest, WithDuplicatesInt) {
    std::vector<int> data = {5, 2, 8, 2, 5, 1, 8, 9, 3, 2};
    PatienceSort<int>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

// Тесты для vector<string>
TEST(PatienceSortTest, AlreadySortedString) {
    std::vector<std::string> data = {"apple", "banana", "cherry", "date"};
    PatienceSort<std::string>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(PatienceSortTest, ReverseSortedString) {
    std::vector<std::string> data = {"date", "cherry", "banana", "apple"};
    PatienceSort<std::string>::sort(data);
    EXPECT_TRUE(std::is_sorted(data.begin(), data.end()));
}

TEST(PatienceSortTest, SingleElementArray) {
    int* single = new int[1];
    single[0] = 42;
    PatienceSort<int>::sort(single, 1);
    EXPECT_EQ(42, single[0]);
    delete[] single;
}

TEST(PatienceSortTest, IntArray) {
    int arr[] = {5, 2, 8, 1, 9, 3};
    const size_t size = sizeof(arr) / sizeof(arr[0]);

    PatienceSort<int>::sort(arr, size);
    EXPECT_TRUE(std::is_sorted(arr, arr + size));
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(9, arr[size - 1]);
}

TEST(PatienceSortTest, StringArray) {
    std::string arr[] = {"zebra", "apple", "monkey", "banana"};
    const size_t size = sizeof(arr) / sizeof(arr[0]);

    PatienceSort<std::string>::sort(arr, size);
    EXPECT_TRUE(std::is_sorted(arr, arr + size));
    EXPECT_EQ("apple", arr[0]);
    EXPECT_EQ("zebra", arr[size - 1]);
}

// Главная функция
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
