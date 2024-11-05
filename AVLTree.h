#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

template <typename T>
class AVLTree {
    struct Node {
        T value;
        int height;
        Node* left;
        Node* right;

        Node(const T& value) : value(value), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    AVLTree();
    ~AVLTree();

    void insert(const T& value);
    void displayTree() const;

private:
    void delete_tree(Node* node);
    int height(Node* node) const;
    int get_height() const;
    int get_balance(Node* node) const;
    Node* rotate_right(Node* y);
    Node* rotate_left(Node* x);
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

#include "AVLTree.cpp" // Include implementation

#endif // AVLTREE_H
