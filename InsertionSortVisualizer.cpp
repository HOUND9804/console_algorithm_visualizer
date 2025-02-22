#include "InsertionSortVisualizer.h"

using namespace std;

InsertionSortVisualizer::InsertionSortVisualizer(const vector<int>& inputArr)
    : arr(inputArr) {}

void InsertionSortVisualizer::printArray(int highlightedIndex1, int highlightedIndex2,int key) const {
    cout << "\nCurrent Array State:\n";
    cout << "current key is:"<<key<<"\n";
    cout << "Green represents element's current position\n";
    cout << "Blue represent element's shifted position\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i == highlightedIndex1) {
            Color::set(10); // Green for elements being moved
        }
        else if(i==highlightedIndex2){
            Color::set(11);
        }else {
            Color::reset();
        }
        string bars(arr[i], '#');
        cout << bars << " (" << arr[i] << ")\n";  // Display hash count
    }
    Color::reset();
    cout << endl;
}

void InsertionSortVisualizer::insertionSort() {
    int n = arr.size();
    cout << "\nSorting process started...\n";

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            printArray(j, j + 1,key); // Highlight movement
            this_thread::sleep_for(chrono::milliseconds(2000));
            --j;
        }
        arr[j + 1] = key;
        // colored[i] = true; // Mark sorted element
        printArray(-1,-1,key); // Update visualization
    }
}

void InsertionSortVisualizer::sort() {
    cout << "Initial array:\n";
    printArray(-1,-1,0);
    insertionSort();
    cout << "Sorting completed! \n";
    cout << "Final Sorted Array:\n";
    printArray(-1,-1,0);
}
