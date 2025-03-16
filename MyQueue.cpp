#include "MyQueue.h"

template <typename T>
MyQueue<T>::MyQueue() : frontNode(nullptr), rearNode(nullptr) {}

template <typename T>
MyQueue<T>::~MyQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void MyQueue<T>::enqueue(const T& value) {
    Node* newNode = new Node(value);
    if (rearNode) {
        rearNode->next = newNode;
    }
    rearNode = newNode;
    if (!frontNode) {
        frontNode = newNode;
    }
}

template <typename T>
void MyQueue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    if (!frontNode) {
        rearNode = nullptr;
    }
    delete temp;
}

template <typename T>
T MyQueue<T>::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty.");
    }
    return frontNode->data;
}

template <typename T>
bool MyQueue<T>::isEmpty() const {
    return frontNode == nullptr;
}

template <typename T>
void MyQueue<T>::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }
    Node* temp = frontNode;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Explicit template instantiation for common types (optional)
template class MyQueue<int>;
template class MyQueue<double>;
template class MyQueue<std::string>;
