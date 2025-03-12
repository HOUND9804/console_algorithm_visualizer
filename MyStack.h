#ifndef MYSTACK_H
#define MYSTACK_H

#include <vector>
#include <iostream>

template <typename T>
class MyStack {
private:
    std::vector<T> stack;

public:
    MyStack() = default;
    void push(const T& value);
    void pop();
    T top() const;
    bool isEmpty() const;
};

#include "MyStack.cpp" // Include implementation file
#endif // MYSTACK_H