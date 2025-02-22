#include <iostream>
#include "AVLTree.h"
#include "Grid.h"
#include "BFS.h" 
#include "DFS.h"
#include "Dijkstra.h"
#include "MergeSortVisualizer.h"
#include "BubbleSortVisualizer.h"
#include "InsertionSortVisualizer.h"
using namespace std;

int main() {
    while (true) {
        Color::reset();
        int choice;
        cout << "Choose an option:\n";
        cout << "1. Use AVL Tree\n";
        cout << "2. Use Grid\n";
        cout << "3. Use Sort\n";
        cout << "0. Exit\n";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting the program.\n";
            break; // Exit the loop to terminate the program
        }

        switch (choice) {
            case 1: { // AVL Tree functionality
                AVLTree<int> tree;
                int n;
                while (true) {
                    cout<<"Enter node number : ";
                    int nodeNum;
                    cin>>nodeNum;
                    for (int i = 0; i < nodeNum; i++) {
                        cout << "Enter a number to insert into the AVL tree: ";
                        int n;
                        cin >> n;
                        tree.insert(n);
                        tree.displayTree();
                    }
                    break;
                }
                break;
            }
            case 2: { // Grid functionality
                int r, c;
                cout << "Enter number of rows and columns for grid: ";
                cin >> r >> c;

                Grid grid(r, c);
                cout << "Enter the grid (use '.' for open space and '#' for blocked space):\n";
                grid.inputGrid();

                cout << "Choose grid action:\n";
                cout << "1. Display grid\n";
                cout << "2. Perform BFS\n";
                cout << "3. Perform DFS\n";
                cout << "4. Find shortest path with Dijkstra's algorithm\n";
                int gridAction;
                cin >> gridAction;

                switch (gridAction) {
                    case 1:
                        cout << "Grid contents:\n";
                        grid.printGrid();
                        break;
                    case 2: {
                        int startX, startY;
                        cout << "Enter starting coordinates (row and column): ";
                        cin >> startX >> startY;
                        BFS bfs(grid);
                        bfs.search(startX, startY);
                        break;
                    }
                    case 3:{
                        int startX, startY;
                        cout << "Enter starting coordinates (row and column): ";
                        cin >> startX >> startY;
                        DFS dfs(grid);
                        dfs.search(startX, startY);
                        break;
                    }
                    case 4: {
                        int startX, startY, endX, endY;
                        cout << "Enter starting coordinates (row and column): ";
                        cin >> startX >> startY;
                        cout << "Enter ending coordinates (row and column): ";
                        cin >> endX >> endY;

                        Dijkstra dijkstra(grid);
                        dijkstra.search(startX, startY, endX, endY);
                        break;
                    }
                    default:
                        cout << "Invalid option. Returning to main menu.\n";
                        break;
                }
                break;
            }
            
            case 3:{
                cout<<"Enter an array of length less than 20 \n";
                cout<<"Enter size of the array \n";
                int n;
                cin>>n;
                cout<<"Enter the array\n";
                vector<int>a(n);
                for(int i=0;i<n;i++){
                    cin>>a[i];
                }
                cout << "Choose an option:\n";
                cout << "1. Use Merge Sort\n";
                cout << "2. Use Bubble Sort\n";
                cout << "3. Use Insertion Sort\n";
                
                int sortingOption;
                cin>>sortingOption;

                switch (sortingOption) {
                    case 1: {
                        MergeSortVisualizer msv(a);
                        msv.sort(); // FIXED: Now it executes the sorting
                        break;
                    }
                    case 2: {
                        BubbleSortVisualizer bsv(a);
                        bsv.sort();
                        break;
                    }
                    case 3: {
                        InsertionSortVisualizer isv(a);
                        isv.sort();
                        break;
                    }
                    default:
                        cout << "Invalid option. Returning to main menu.\n";
                        break;
                }
            }
            default:
            cout << "Invalid option. Please try again.\n";
        }
    }
    return 0; // End of the program
}
