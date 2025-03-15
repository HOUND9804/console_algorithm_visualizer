#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

template <typename T>
class MyQueue {
public:
    MyQueue();
    ~MyQueue();
    void push(const T& value);
    void pop();
    T front() const;
    bool empty() const;
    size_t size() const;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t queue_size;
};

// Constructor: Initializes an empty queue.
template <typename T>
MyQueue<T>::MyQueue() : head(nullptr), tail(nullptr), queue_size(0) {}

// Destructor: Clears the queue and deletes all nodes.
template <typename T>
MyQueue<T>::~MyQueue() {
    while (!empty()) {
        pop();
    }
}

// Pushes a new element to the back of the queue.
template <typename T>
void MyQueue<T>::push(const T& value) {
    Node* newNode = new Node(value);  // Create a new node
    if (tail) {
        tail->next = newNode;  // Attach to the tail if the queue isn't empty
    }
    tail = newNode;  // Update the tail pointer
    if (!head) {
        head = newNode;  // Set head to the new node if the queue was empty
    }
    queue_size++;  // Increment the size of the queue
}

// Pops the front element from the queue.
template <typename T>
void MyQueue<T>::pop() {
    if (empty()) {
        std::cout << "Queue is empty." << std::endl;  // Print error message if the queue is empty
        return;
    }
    Node* temp = head;
    head = head->next;  // Move the head to the next node
    delete temp;  // Delete the old head
    if (!head) {
        tail = nullptr;  // If the queue is empty now, reset the tail to nullptr
    }
    queue_size--;  // Decrement the size of the queue
}

// Returns the front element of the queue without removing it.
template <typename T>
T MyQueue<T>::front() const {
    if (empty()) {
        std::cout << "Queue is empty." << std::endl;  // Print error message if the queue is empty
        return T();  // Return a default value of T
    }
    return head->data;  // Return the data in the front node
}

// Checks if the queue is empty.
template <typename T>
bool MyQueue<T>::empty() const {
    return queue_size == 0;  // Queue is empty if size is 0
}

// Returns the size of the queue.
template <typename T>
size_t MyQueue<T>::size() const {
    return queue_size;  // Return the current size of the queue
}

// Explicit template instantiation for common types
template class MyQueue<int>;
template class MyQueue<double>;
template class MyQueue<std::string>;
template class MyQueue<std::pair<int, int>>;  // Explicit instantiation for pair<int, int>

#endif // MYQUEUE_H







