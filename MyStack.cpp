#include "MyStack.h"

template <typename T>
MyStack<T>::MyStack() : capacity(10), size(0) {
    stack = new T[capacity];
}

template <typename T>
MyStack<T>::~MyStack() {
    delete[] stack;
}

template <typename T>
void MyStack<T>::resize() {
    capacity *= 2;
    T* newStack = new T[capacity];
    for (int i = 0; i < size; ++i) {
        newStack[i] = stack[i];
    }
    delete[] stack;
    stack = newStack;
}

template <typename T>
void MyStack<T>::push(const T& value) {
    if (size == capacity) {
        resize();
    }
    stack[size++] = value;
}

template <typename T>
void MyStack<T>::pop() {
    if (!isEmpty()) {
        --size;
    } else {
        std::cerr << "Stack is empty! Cannot pop.\n";
    }
}

template <typename T>
T MyStack<T>::top() const {
    if (!isEmpty()) {
        return stack[size - 1];
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

template <typename T>
bool MyStack<T>::isEmpty() const {
    return size == 0;
}

// Explicit template instantiation for common types
template class MyStack<int>;
template class MyStack<std::pair<int, int>>;



