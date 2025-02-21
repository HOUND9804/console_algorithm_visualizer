#ifndef MERGESORTVISUALIZER_H
#define MERGESORTVISUALIZER_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include "Color.h"

using namespace std;

class MergeSortVisualizer {
private:
    vector<int> arr;
    
    void printArray(const vector<int>& subArray, int depth, const string& label) const;
    void merge(vector<int>& arr, int left, int mid, int right, int depth);
    void mergeSort(vector<int>& arr, int left, int right, int depth);

public:
    MergeSortVisualizer(const vector<int>& inputArr);
    void sort();
};
#include"MergeSortVisualizer.cpp"
#endif // MERGESORTVISUALIZER_H
