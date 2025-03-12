#include "InsertionSortVisualizer.h"

using namespace std;

InsertionSortVisualizer::InsertionSortVisualizer(const vector<int>& inputArr)
    : arr(inputArr), colored(inputArr.size(), false) {}

void InsertionSortVisualizer::printArray(int highlightedIndex1, int highlightedIndex2) const {
    cout << "\nCurrent Array State:\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i == highlightedIndex1 || i == highlightedIndex2) {
            Color::set(10); // Green for  the elements being moved
        } else if (colored[i]) {
            Color::set(12); // Red for the sorted elements
        } else {
            Color::reset();
        }
        string bars(arr[i], '#');
        cout << bars << " (" << arr[i] << ")\n";  // Display the hash count
    }
    Color::reset();
    cout << endl;
}

void InsertionSortVisualizer::insertionSort() {
    int n = arr.size();
    cout << "\nSorting process started...\n";
    cout << " Red represents sorted elements.\n";
    cout << " Green represents elements being moved during sorting.\n\n";

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            printArray(j, j + 1); // Highlight movement
            this_thread::sleep_for(chrono::milliseconds(500));
            --j;
        }
        arr[j + 1] = key;
        colored[i] = true; // Mark sorted element
        printArray(); // Update visualization
    }
}

void InsertionSortVisualizer::sort() {
    cout << "Initial array:\n";
    printArray();
    insertionSort();
    cout << "Sorting completed! \n";
    cout << "Final Sorted Array:\n";
    printArray();
}
