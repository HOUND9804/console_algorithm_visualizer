#ifndef INSERTIONSORTVISUALIZER_H
#define INSERTIONSORTVISUALIZER_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Color.h"

class InsertionSortVisualizer {
private:
    std::vector<int> arr;
    std::vector<bool> colored;

    void printArray(int highlightedIndex1 = -1, int highlightedIndex2 = -1) const;
    void insertionSort();

public:
    InsertionSortVisualizer(const std::vector<int>& inputArr);
    void sort();
};
#include "InsertionSortVisualizer.cpp"
#endif // INSERTIONSORTVISUALIZER_H
