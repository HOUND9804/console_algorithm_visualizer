#include "MyQueue.h"

template <typename T>
void MyQueue<T>::enqueue(const T& value) {
    queue.push_back(value);  // Add element to the back of the queue
}

template <typename T>
void MyQueue<T>::dequeue() {
    if (!queue.empty()) {
        queue.pop_front();  // Remove element from the front of the queue
    } else {
        std::cerr << "Queue is empty! Cannot dequeue.\n";
    }
}

template <typename T>
T MyQueue<T>::front() const {
    if (!queue.empty()) {
        return queue.front();  // Return the front element without removing it
    } else {
        throw std::out_of_range("Queue is empty");
    }
}

template <typename T>
bool MyQueue<T>::isEmpty() const {
    return queue.empty();  // Check if the queue is empty
}

template <typename T>
size_t MyQueue<T>::size() const {
    return queue.size();  // Return the size of the queue
}

// Explicit template instantiation for common types
template class MyQueue<int>;
template class MyQueue<std::pair<int, int>>;
