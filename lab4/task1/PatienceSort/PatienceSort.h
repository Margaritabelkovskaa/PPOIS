#pragma once
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
void patienceSort(std::vector<T>& data) {
    if (data.empty()) return;

    std::vector<std::vector<T>> piles;

    for (const T& element : data) {
        bool placed = false;
        for (auto& pile : piles) {
            if (pile.back() >= element) {
                pile.push_back(element);
                placed = true;
                break;
            }
        }
        if (!placed) {
            piles.push_back(std::vector<T>{element});
        }
    }

    data.clear();

    while (!piles.empty()) {
        size_t minIndex = 0;
        for (size_t i = 1; i < piles.size(); ++i) {
            if (piles[i].back() < piles[minIndex].back()) {
                minIndex = i;
            }
        }

        data.push_back(piles[minIndex].back());
        piles[minIndex].pop_back();

        if (piles[minIndex].empty()) {
            piles.erase(piles.begin() + minIndex);
        }
    }
}

template <typename T>
void patienceSort(T* array, size_t size) {
    std::vector<T> temp(array, array + size);
    patienceSort(temp);
    std::copy(temp.begin(), temp.end(), array);
}