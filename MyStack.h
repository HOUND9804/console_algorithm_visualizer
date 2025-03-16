#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>

template <typename T>
class MyStack {
public:
    MyStack();
    ~MyStack();

    void push(const T& value);
    void pop();
    T top() const;
    bool isEmpty() const;
    void display() const;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topNode;
};

#include "MyStack.cpp"

#endif // MYSTACK_H
