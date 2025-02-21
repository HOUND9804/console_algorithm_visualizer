#include "MergeSortVisualizer.h"

MergeSortVisualizer::MergeSortVisualizer(const vector<int>& inputArr) : arr(inputArr) {}

void MergeSortVisualizer::printArray(const vector<int>& subArray, int depth, const string& label) const {
    cout << string(depth * 4, ' ') << label << "\n";
    for (int num : subArray) {
        cout << string(depth * 4, ' ');
        Color::set(10);
        cout << string(num, '#') << num << endl;
        Color::reset();
    }
    cout << endl;
}

void MergeSortVisualizer::merge(vector<int>& arr, int left, int mid, int right, int depth) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    printArray(L, depth, "Left Array");
    printArray(R, depth, "Right Array");
    this_thread::sleep_for(chrono::milliseconds(1000));

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }

    printArray(vector<int>(arr.begin() + left, arr.begin() + right + 1), depth, "Merged Array");
    this_thread::sleep_for(chrono::milliseconds(1000));
}

void MergeSortVisualizer::mergeSort(vector<int>& arr, int left, int right, int depth) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);
        merge(arr, left, mid, right, depth);
    }
}

void MergeSortVisualizer::sort() {
    cout << "Starting Merge Sort:\n";
    mergeSort(arr, 0, arr.size() - 1, 0);
    cout << "Sorted Array:\n";
    printArray(arr, 0, "Final Sorted Array");
}
