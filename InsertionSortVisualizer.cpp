#include "InsertionSortVisualizer.h"
#include <algorithm> 
#include <chrono>    
#include <thread>    

using namespace std;

// Constructor
InsertionSortVisualizer::InsertionSortVisualizer(const vector<int>& inputArr)
    : arr(inputArr) {}

// Function to format the number with spaces and return the middle part
string InsertionSortVisualizer::printNum(int num) const {
    string s = " " + to_string(num) + " "; // Add spaces to the front and back
    int middle = s.length() / 2;          // Calculate the middle index
    return string(1, s[middle - 1]) + s[middle] + s[middle + 1]; // Return middle and its two sides
}

// Function to print the array and grid
void InsertionSortVisualizer::printArray(int highlightedIndex1, int highlightedIndex2, int key) const {
    cout << "\nCurrent Array State:\n";
    cout << "Current key is: " << key << "\n";
    cout << "Green represents the element's current position.\n";
    cout << "Blue represents the element's shifted position.\n";

    // Find the maximum value in the array to determine the height of the bars
    int maxHeight = *max_element(arr.begin(), arr.end());

    // Print the grid with vertical bars
    for (int level = maxHeight; level >= 1; --level) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (i == highlightedIndex1) {
                Color::set(10); // Green for the current position
            } else if (i == highlightedIndex2) {
                Color::set(11); // Blue for the shifted position
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

// Function to perform insertion sort
void InsertionSortVisualizer::insertionSort() {
    int n = arr.size();
    cout << "\nSorting process started...\n";

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            printArray(j, j + 1, key); // Highlight movement
            this_thread::sleep_for(chrono::milliseconds(1000));
            --j;
        }
        arr[j + 1] = key;
        printArray(-1, -1, key); // Update visualization
    }
}

// Function to start the sorting process
void InsertionSortVisualizer::sort() {
    cout << "Initial array:\n";
    printArray(-1, -1, 0);
    insertionSort();
    cout << "Sorting completed!\n";
    cout << "Final Sorted Array:\n";
    printArray(-1, -1, 0);
}