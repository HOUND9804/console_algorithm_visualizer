#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>

template <typename T>
class MyStack {
private:
    T* stack;
    int capacity;
    int size;

    void resize();

public:
    MyStack();
    ~MyStack();

    void push(const T& value);
    void pop();
    T top() const;
    bool isEmpty() const;
};

#include "MyStack.cpp" // Include implementation file

#endif // MYSTACK_H
