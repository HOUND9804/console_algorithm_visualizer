#include <iostream>
#include "AVLTree.h"
#include "BST.h"
#include "Grid.h"
#include "BFS.h" 
#include "DFS.h"
#include "Dijkstra.h"
#include "MergeSortTree.h"
#include "BubbleSortVisualizer.h"
#include "InsertionSortVisualizer.h"
using namespace std;

int main() {
    while (true) {
        Color::reset();
        int choice;
        cout << "Choose an option:\n";
        cout << "1. Use Tree\n";
        cout << "2. Use Grid\n";
        cout << "3. Use Sort\n";
        cout << "0. Exit\n";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting the program.\n";
            break; // Exit the loop to terminate the program
        }

        switch (choice) {
            case 1: { //Tree functionality
                cout<<"0. BST \n";
                cout<<"1. AVL Tree\n";
                int op;
                cin>>op;
                switch(op){
                    case 0: { 
                        BST<int> bst;  
                        cout << "Enter the number of nodes to insert into the BST: ";
                        int nodeNum;
                        cin >> nodeNum;
            
                        for (int i = 0; i < nodeNum; i++) {
                            cout << "Enter a number to insert into the BST: ";
                            int n;
                            cin >> n;
                            bst.insert(n);
                            bst.displayTree();
                        }
                        break;
                    }
            
                    case 1: { 
                        AVLTree<int> tree;
                        cout << "Enter the number of nodes to insert into the AVL tree: ";
                        int nodeNum;
                        cin >> nodeNum;
            
                        for (int i = 0; i < nodeNum; i++) {
                            cout << "Enter a number to insert into the AVL tree: ";
                            int n;
                            cin >> n;
                            tree.insert(n);
                            tree.displayTree();
                        }
                        break;
                    }
            
                    default:
                        cout << "Invalid option. Please enter 0 or 1.\n";
                        break;
                }
                break;
            }

            case 2: { // Grid functionality

                cout << "Choose grid action:\n";
                cout << "1. Perform BFS\n";
                cout << "2. Perform DFS\n";
                cout << "3. Find shortest path with Dijkstra's algorithm\n";
                int gridAction;
                cin >> gridAction;

                switch (gridAction) {
                    case 1: {
                        int r, c;
                    cout << "Enter number of rows and columns for grid: ";
                    cin >> r >> c;

                    Grid grid(r, c);
                    cout << "Enter the grid (use '.' for open space and '#' for blocked space):\n";
                    grid.inputGrid();

                    int startX, startY;
                    cout << "Enter starting coordinates (row and column): ";
                    cin >> startX >> startY;
                    BFS bfs(grid);
                    bfs.search(startX, startY);
                    break;
                    }
                    case 2:{
                        int r, c;
                    cout << "Enter number of rows and columns for grid: ";
                    cin >> r >> c;

                    Grid grid(r, c);
                    cout << "Enter the grid (use '.' for open space and '#' for blocked space):\n";
                    grid.inputGrid();
                        int startX, startY;
                        cout << "Enter starting coordinates (row and column): ";
                        cin >> startX >> startY;
                        DFS dfs(grid);
                        dfs.search(startX, startY);
                        break;
                    }
                    case 3: {
                        int r, c;
                    cout << "Enter number of rows and columns for grid: ";
                    cin >> r >> c;
                    Grid grid(r, c);
                    cout << "Enter the grid (use 1,2...9 for weight of the cell and open space and '#' for blocked space):\n";
                    grid.inputGrid();
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
                cout << "Choose an option:\n";
                cout << "1. Use Merge Sort\n";
                cout << "2. Use Bubble Sort\n";
                cout << "3. Use Insertion Sort\n";
                
                int sortingOption;
                cin>>sortingOption;

                switch (sortingOption) {
                    case 1: {
                        cout<<"Enter an array of length less than 15 \n";
                        cout<<"Enter size of the array \n";
                        int n;
                        cin>>n;
                        cout<<"Enter the array\n";
                        vector<int>a(n);
                        for(int i=0;i<n;i++){
                            cin>>a[i];
                        }
                        MergeSortTree<int> tree(a);
                        tree.visualize_merge_sort();
                        break;
                    }
                    case 2: {
                        cout<<"Enter an array of length less than 15 \n";
                        cout<<"Enter size of the array \n";
                        int n;
                        cin>>n;
                        cout<<"Enter the array\n";
                        cout<<"Enter number greater than 0 and smaller than 20 \n";
                        vector<int>a(n);
                        for(int i=0;i<n;i++){
                            cin>>a[i];
                        }
                        BubbleSortVisualizer bsv(a);
                        bsv.sort();
                        break;
                    }
                    case 3: {
                        cout<<"Enter an array of length less than 15 \n";
                        cout<<"Enter size of the array \n";
                        int n;
                        cin>>n;
                        cout<<"Enter the array\n";
                        cout<<"Enter number greater than 0 and smaller than 20 \n";
                        vector<int>a(n);
                        for(int i=0;i<n;i++){
                            cin>>a[i];
                        }
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
