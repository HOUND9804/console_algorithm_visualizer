#include "MyStack.h"

template <typename T>
MyStack<T>::MyStack() : topNode(nullptr) {}

template <typename T>
MyStack<T>::~MyStack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void MyStack<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
}

template <typename T>
void MyStack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty. Cannot pop.\n";
        return;
    }
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

template <typename T>
T MyStack<T>::top() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty.");
    }
    return topNode->data;
}

template <typename T>
bool MyStack<T>::isEmpty() const {
    return topNode == nullptr;
}

template <typename T>
void MyStack<T>::display() const {
    if (isEmpty()) {
        std::cout << "Stack is empty.\n";
        return;
    }
    Node* temp = topNode;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Explicit template instantiation for common types (optional)
template class MyStack<int>;
template class MyStack<double>;
template class MyStack<std::string>;
