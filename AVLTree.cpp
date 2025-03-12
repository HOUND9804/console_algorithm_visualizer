#include "AVLTree.h"

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
AVLTree<T>::~AVLTree() {
    delete_tree(root);
}

template <typename T>
void AVLTree<T>::insert(const T& value) {
    root = insert(root, value);
}

template <typename T>
void AVLTree<T>::displayTree() const {
    const int depth = get_height();
    if (depth == 0) {
        std::cout << "<empty tree>\n";
        return;
    }

    auto rows_disp = get_row_display();
    auto formatted_rows = row_formatter(rows_disp);
    trim_rows_left(formatted_rows);
    for (const auto& row : formatted_rows) {
        std::cout << ' ' << row << '\n';
    }
}

template <typename T>
void AVLTree<T>::delete_tree(Node* node) {
    if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

template <typename T>
int AVLTree<T>::height(Node* node) const {
    return node ? node->height : 0;
}

template <typename T>
int AVLTree<T>::get_height() const {
    return height(root);
}

template <typename T>
int AVLTree<T>::get_balance(Node* node) const {
    return node ? height(node->left) - height(node->right) : 0;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotate_right(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotate_left(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return y;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::insert(Node* node, const T& value) {
    if (!node) return new Node(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node; // Duplicate values are not allowed.

    // Update height
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = get_balance(node);

    // Balance the tree
    if (balance > 1 && value < node->left->value)
        return rotate_right(node);

    if (balance < -1 && value > node->right->value)
        return rotate_left(node);

    if (balance > 1 && value > node->left->value) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if (balance < -1 && value < node->right->value) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

template <typename T>
typename AVLTree<T>::display_rows AVLTree<T>::get_row_display() const {
    std::vector<Node*> traversal_stack;
    std::vector<std::vector<Node*>> rows;
    if (!root) return display_rows();

    Node* p = root;
    const int max_depth = get_height();
    rows.resize(max_depth);
    int depth = 0;
    for (;;) {
        if (depth == max_depth - 1) {
            rows[depth].push_back(p);
            if (depth == 0) break;
            --depth;
            continue;
        }

        if (traversal_stack.size() == depth) {
            rows[depth].push_back(p);
            traversal_stack.push_back(p);
            if (p) p = p->left;
            ++depth;
            continue;
        }

        if (rows[depth + 1].size() % 2) {
            p = traversal_stack.back();
            if (p) p = p->right;
            ++depth;
            continue;
        }

        if (depth == 0) break;

        traversal_stack.pop_back();
        p = traversal_stack.back();
        --depth;
    }

    display_rows rows_disp;
    std::stringstream ss;
    for (const auto& row : rows) {
        rows_disp.emplace_back();
        for (Node* pn : row) {
            if (pn) {
                ss << pn->value;
                rows_disp.back().push_back(cell_display(ss.str()));
                ss = std::stringstream();
            } else {
                rows_disp.back().push_back(cell_display());
            }
        }
    }
    return rows_disp;
}

template <typename T>
std::vector<std::string> AVLTree<T>::row_formatter(const display_rows& rows_disp) const {
    using s_t = std::string::size_type;
    s_t cell_width = 0;
    for (const auto& row_disp : rows_disp) {
        for (const auto& cd : row_disp) {
            if (cd.present && cd.valstr.length() > cell_width) {
                cell_width = cd.valstr.length();
            }
        }
    }
    if (cell_width % 2 == 0) ++cell_width;
    if (cell_width < 3) cell_width = 3;

    std::vector<std::string> formatted_rows;
    s_t row_count = rows_disp.size();
    s_t row_elem_count = 1 << (row_count - 1);
    s_t left_pad = 0;

    for (s_t r = 0; r < row_count; ++r) {
        const auto& cd_row = rows_disp[row_count - r - 1];
        s_t space = (s_t(1) << r) * (cell_width + 1) / 2 - 1;
        std::string row;
        for (s_t c = 0; c < row_elem_count; ++c) {
            row += std::string(c ? left_pad * 2 + 1 : left_pad, ' ');
            if (cd_row[c].present) {
                const std::string& valstr = cd_row[c].valstr;
                s_t long_padding = cell_width - valstr.length();
                s_t short_padding = long_padding / 2;
                long_padding -= short_padding;
                row += std::string(c % 2 ? short_padding : long_padding, ' ');
                row += valstr;
                row += std::string(c % 2 ? long_padding : short_padding, ' ');
            } else {
                row += std::string(cell_width, ' ');
            }
        }
        formatted_rows.push_back(row);
        if (row_elem_count == 1) break;

        s_t left_space = space + 1;
        s_t right_space = space - 1;
        for (s_t sr = 0; sr < space; ++sr) {
            std::string row;
            for (s_t c = 0; c < row_elem_count; ++c) {
                if (c % 2 == 0) {
                    row += std::string(c ? left_space * 2 + 1 : left_space, ' ');
                    row += cd_row[c].present ? '/' : ' ';
                    row += std::string(right_space + 1, ' ');
                } else {
                    row += std::string(right_space, ' ');
                    row += cd_row[c].present ? '\\' : ' ';
                }
            }
            formatted_rows.push_back(row);
            ++left_space;
            --right_space;
        }
        left_pad += space + 1;
        row_elem_count /= 2;
    }
    std::reverse(formatted_rows.begin(), formatted_rows.end());
    return formatted_rows;
}

template <typename T>
void AVLTree<T>::trim_rows_left(std::vector<std::string>& rows) {
    if (!rows.size()) return;
    auto min_space = rows.front().length();
    for (const auto& row : rows) {
        auto i = row.find_first_not_of(' ');
        if (i == std::string::npos) i = row.length();
        if (i == 0) return;
        if (i < min_space) min_space = i;
    }
    for (auto& row : rows) {
        row.erase(0, min_space);
    }
}

template <typename T>
AVLTree<T>::cell_display::cell_display() : present(false) {}

template <typename T>
AVLTree<T>::cell_display::cell_display(std::string valstr) : valstr(valstr), present(true) {}
