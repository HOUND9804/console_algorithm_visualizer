#ifndef MERGESORTTREE_H
#define MERGESORTTREE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "MyQueue.h"
#include <map>
#include <conio.h>  
using namespace std;

template <typename T>
class MergeSortTree {
public:
    struct Node {
        vector<T> subarray;
        Node* left;
        Node* right;
        int depth;
        int position;
        bool is_merged = false;
        bool is_merging = false;  // Flag for nodes currently being merged

        Node(vector<T> arr, int d = 0, int p = 0) 
            : subarray(arr), left(nullptr), right(nullptr), depth(d), position(p) {}
    };

    MergeSortTree(const vector<T>& arr) : root(new Node(arr)) {
        build_tree(root);
        tree_height = calculate_height(root);
        collect_nodes_by_level();
    }

    ~MergeSortTree() { delete_tree(root); }

    void visualize_merge_sort() {
        cout << "Merge Sort Tree Visualization\n";
        cout << "Press SPACE to proceed to the next step.\n\n";
        
        // Display the initial tree
        display_tree();
        wait_for_space();
        
        // Start from the bottom level (excluding leaf nodes with single elements)
        for (int level = tree_height - 2; level >= 0; level--) {
            for (Node* node : nodes_by_level[level]) {
                if (node->left && node->right) {
                    // Mark the node and its children as currently merging
                    node->is_merging = true;
                    node->left->is_merging = true;
                    node->right->is_merging = true;
                    
                    // Display the tree with highlighted nodes
                    cout << "\033[H\033[J";  // Clear screen
                    display_tree();
                    cout<<"M represent merging\n";
                    cout<<"* represent already merged\n";
                    cout << "\nMerging subarrays at level " << level << "...\n";
                    wait_for_space();
                    
                    // Merge the subarrays
                    merge_subarrays(node);
                    
                    // Mark the node as merged and clear the merging flags
                    node->is_merged = true;
                    node->is_merging = false;
                    node->left->is_merging = false;
                    node->right->is_merging = false;
                    
                    // Display the tree after merging
                    cout << "\033[H\033[J";  // Clear screen
                    display_tree();
                    cout << "\nMerged node at level " << level << "\n";
                    wait_for_space();
                }
            }
        }
        
        cout << "\nMerge Sort Complete!\n";
    }

private:
    Node* root;
    int tree_height;
    vector<vector<Node*>> nodes_by_level;

    void build_tree(Node* node) {
        if (node->subarray.size() <= 1) return;

        size_t mid = node->subarray.size() / 2;
        node->left = new Node(
            vector<T>(node->subarray.begin(), node->subarray.begin() + mid),
            node->depth + 1,
            node->position * 2
        );
        node->right = new Node(
            vector<T>(node->subarray.begin() + mid, node->subarray.end()),
            node->depth + 1,
            node->position * 2 + 1
        );

        build_tree(node->left);
        build_tree(node->right);
    }

    void collect_nodes_by_level() {
        nodes_by_level.clear();
        nodes_by_level.resize(tree_height);
        
        MyQueue<Node*> q;
        q.enqueue(root);
        
        while (!q.isEmpty()) {
            Node* node = q.front();
            q.dequeue();
            
            if (node->depth < tree_height) {
                nodes_by_level[node->depth].push_back(node);
            }
            
            if (node->left) q.enqueue(node->left);
            if (node->right) q.enqueue(node->right);
        }
    }

    int calculate_height(Node* node) {
        if (!node) return 0;
        return 1 + max(calculate_height(node->left), calculate_height(node->right));
    }

    void display_tree() {
        int console_width = 100;  // Adjust based on your console width
        
        // Prepare the display grid
        vector<string> display(tree_height * 2, string(console_width, ' '));
        
        // Fill in the display grid
        fill_display(display, root, 0, 0, console_width);
        
        // Print the display grid
        for (const auto& line : display) {
            for(auto& c:line){
                if(c=='M'){
                    Color::set(4);
                    cout<<c;
                }
                else{
                    Color::reset();
                    cout<<c;
                }
                
            }
            cout<<endl;
        }
    }

    void wait_for_space() {
        cout << "\nPress SPACE to continue...";
        char key;
        do {
            key = _getch();
        } while (key != ' ');
        cout << "\n";
    }

    void merge_subarrays(Node* node) {
        if (!node->left || !node->right) return;
        
        const vector<T>& left_array = node->left->subarray;
        const vector<T>& right_array = node->right->subarray;
        
        vector<T> merged;
        size_t i = 0, j = 0;
        
        // Merge the two sorted subarrays
        while (i < left_array.size() && j < right_array.size()) {
            if (left_array[i] <= right_array[j]) {
                merged.push_back(left_array[i]);
                ++i;
            } else {
                merged.push_back(right_array[j]);
                ++j;
            }
        }
        
        // Add remaining elements
        while (i < left_array.size()) {
            merged.push_back(left_array[i]);
            ++i;
        }
        
        while (j < right_array.size()) {
            merged.push_back(right_array[j]);
            ++j;
        }
        
        // Update the node's subarray with the merged result
        node->subarray = merged;
    }

    void delete_tree(Node* node) {
        if (node) {
            delete_tree(node->left);
            delete_tree(node->right);
            delete node;
        }
    }
    
    string array_to_string(const vector<T>& arr) {
        stringstream ss;
        ss << "[";
        for (size_t i = 0; i < arr.size(); ++i) {
            ss << arr[i];
            if (i < arr.size() - 1) ss << " ";
        }
        ss << "]";
        return ss.str();
    }
    
    void fill_display(vector<string>& display, Node* node, int depth, int start, int end) {
        if (!node) return;
        
        int mid = (start + end) / 2;
        string node_str = array_to_string(node->subarray);
        
        // Center the node string
        int node_start = mid - node_str.length() / 2;
        
        // Add the node string to the display
        if (node->is_merging || node->is_merged) {
            display[depth].replace(node_start, node_str.length(), node_str);
            
            if (node_start + node_str.length() + 1 < display[depth].length()) {
                display[depth][node_start + node_str.length() + 1] = node->is_merging ? 'M' : '*';
            }
        } else {
            for (size_t i = 0; i < node_str.length(); ++i) {
                if (node_start + i < display[depth].length()) {
                    display[depth][node_start + i] = node_str[i];
                }
            }
        }
        
        // Draw branches if there are children
        if (node->left) {
            int left_mid = (start + mid) / 2;
            for (int i = 1; i <= (mid - left_mid) / 2; ++i) {
                if (mid - i < display[depth + 1].length()) {
                    display[depth + 1][mid - i] = '/';
                }
            }
            fill_display(display, node->left, depth + 2, start, mid);
        }
        
        if (node->right) {
            int right_mid = (mid + end) / 2;
            for (int i = 1; i <= (right_mid - mid) / 2; ++i) {
                if (mid + i <= display[depth + 1].length()) {         
                    display[depth + 1][mid + i] = '\\';
                }
            }
            fill_display(display, node->right, depth + 2, mid, end);
        }
    }
};

#endif // MERGESORTTREE_H