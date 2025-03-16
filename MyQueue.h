#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

template <typename T>
class MyQueue {
public:
    MyQueue();
    ~MyQueue();

    void enqueue(const T& value);
    void dequeue();
    T front() const;
    bool isEmpty() const;
    void display() const;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
};

#include "MyQueue.cpp"

#endif // MYQUEUE_H
