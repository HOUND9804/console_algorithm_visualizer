#include "BubbleSortVisualizer.h"
#include <algorithm> // For max_element
#include <chrono>    // For std::chrono::milliseconds
#include <thread>    // For std::this_thread::sleep_for

using namespace std;

BubbleSortVisualizer::BubbleSortVisualizer(const vector<int>& inputArr)
    : arr(inputArr), colored(inputArr.size(), false) {}

// Function to format the number with spaces and return the middle part
string BubbleSortVisualizer::printNum(int num) const {
    string s = " " + to_string(num) + " "; // Add spaces to the front and back
    int middle = s.length() / 2;          // Calculate the middle index
    return string(1, s[middle - 1]) + s[middle] + s[middle + 1]; // Return middle and its two sides
}

void BubbleSortVisualizer::printArray(int highlightedIndex1, int highlightedIndex2) const {
    cout << "\nCurrent Array State:\n";
    cout << " Red represents sorted elements.\n";
    cout << " Green represents elements being swapped (transition phase).\n";

    // Find the maximum value in the array to determine the height of the bars
    int maxHeight = *max_element(arr.begin(), arr.end());

    // Print the grid with vertical bars
    for (int level = maxHeight; level >= 1; --level) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (i == highlightedIndex1 || i == highlightedIndex2) {
                Color::set(10); // Green for elements being swapped (transition)
            } else if (colored[i]) {
                Color::set(12); // Red for sorted elements
            } else {
                Color::reset();
            }

            if (arr[i] > level) {
                cout << " # "; // Print a bar segment in the middle column
            } else if (arr[i] == level) {
                cout << printNum(arr[i]); // Print the number at the current level
            } else {
                cout << "   "; // Print empty space
            }
            Color::reset(); // Reset color after each element
        }
        cout << endl;
    }

    // Print the array indices at the bottom
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << " " << i << " "; // Print the index of each element
    }
    cout << endl << endl;
}

void BubbleSortVisualizer::bubbleSort() {
    int n = arr.size();
    cout << "\nSorting process started...\n";

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                printArray(j, j + 1); // Highlight elements being swapped in green
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
        }
        colored[n - i - 1] = true; // Mark last sorted element in red
        printArray(); // Update visualization
        if (!swapped) break; // Optimized bubble sort
    }
}

void BubbleSortVisualizer::sort() {
    cout << "Initial array:\n";
    printArray();
    bubbleSort();
    cout << "Sorting completed!\n";
    cout << "Final Sorted Array:\n";
    printArray();
}