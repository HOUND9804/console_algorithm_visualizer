#ifndef BUBBLESORTVISUALIZER_H
#define BUBBLESORTVISUALIZER_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Color.h"

class BubbleSortVisualizer {
private:
    std::vector<int> arr;
    std::vector<bool> colored;

    string printNum(int n) const;
    void printArray(int highlightedIndex1 = -1, int highlightedIndex2 = -1) const;
    void bubbleSort();

public:
    BubbleSortVisualizer(const std::vector<int>& inputArr);
    void sort();
};
#include "BubbleSortVisualizer.cpp"
#endif // BUBBLESORTVISUALIZER_H
