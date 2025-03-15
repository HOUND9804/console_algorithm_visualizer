#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <deque>
#include <iostream>

template <typename T>
class MyQueue {
private:
    std::deque<T> queue;  // Underlying container for the queue

public:
    MyQueue() = default;
    void enqueue(const T& value);
    void dequeue();
    T front() const;
    bool isEmpty() const;
    size_t size() const;
};

#include "MyQueue.cpp" // Include implementation file

#endif // MYQUEUE_H
