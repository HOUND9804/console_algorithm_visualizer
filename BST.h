#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
class BST {
    struct Node {
        T value;
        int height;
        Node* left;
        Node* right;

        Node(const T& value) : value(value), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BST();
    ~BST();

    void insert(const T& value);
    void displayTree() const;

private:
    void delete_tree(Node* node);
    int height(Node* node) const;
    int get_height() const;
    Node* insert(Node* node, const T& value);
    
    struct cell_display {
        std::string valstr;
        bool present;
        cell_display();
        cell_display(std::string valstr);
    };
    
    using display_rows = std::vector<std::vector<cell_display>>;
    display_rows get_row_display() const;
    std::vector<std::string> row_formatter(const display_rows& rows_disp) const;
    static void trim_rows_left(std::vector<std::string>& rows);
};

#include "BST.cpp" // Include implementation

#endif // BST_H
