#include "MyStack.h"

template <typename T>
void MyStack<T>::push(const T& value) {
    stack.push_back(value);
}

template <typename T>
void MyStack<T>::pop() {
    if (!stack.empty()) {
        stack.pop_back();
    } else {
        std::cerr << "Stack is empty !! Cannot pop.\n";
    }
}

template <typename T>
T MyStack<T>::top() const {
    if (!stack.empty()) {
        return stack.back();
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

template <typename T>
bool MyStack<T>::isEmpty() const {
    return stack.empty();
}

// Explicit template instantiation for common types
template class MyStack<int>;
template class MyStack<std::pair<int, int>>;

