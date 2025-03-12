#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <vector>
#include <iostream>

template <typename T>
class MyQueue {
private:
    std::vector<T> queue;  // Using vector instead of deque

public:
    MyQueue() = default;

    // Enqueue an element at the back of the queue
    void enqueue(const T& value);

    // Dequeue an element from the front of the queue
    void dequeue();

    // Get the front element of the queue
    T front() const;

    // Check if the queue is empty
    bool isEmpty() const;

    // Get the size of the queue
    size_t size() const;
};

#include "MyQueue.cpp" // Include implementation file

#endif // MYQUEUE_H
