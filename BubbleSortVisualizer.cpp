#include "BubbleSortVisualizer.h"

using namespace std;

BubbleSortVisualizer::BubbleSortVisualizer(const vector<int>& inputArr)
    : arr(inputArr), colored(inputArr.size(), false) {}

void BubbleSortVisualizer::printArray(int highlightedIndex1, int highlightedIndex2) const {
    cout << "\nCurrent Array State:\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i == highlightedIndex1 || i == highlightedIndex2) {
            Color::set(10); // Green for elements being swapped (transition)
        } else if (colored[i]) {
            Color::set(12); // Red for sorted elements
        } else {
            Color::reset();
        }
        string bars(arr[i], '#');
        cout << bars << " (" << arr[i] << ")\n";  // Display hash count
    }
    Color::reset();
    cout << endl;
}

void BubbleSortVisualizer::bubbleSort() {
    int n = arr.size();
    cout << "\nSorting process started...\n";
    cout << " Red represents sorted elements.\n";
    cout << " Green represents elements being swapped (transition phase).\n";

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                printArray(j, j + 1); // Highlight elements being swapped in green
                this_thread::sleep_for(chrono::milliseconds(500));
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
