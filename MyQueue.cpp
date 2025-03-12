#include "MyQueue.h"

template <typename T>
void MyQueue<T>::enqueue(const T& value) {
    queue.push_back(value);  // Insert at the back
}

template <typename T>
void MyQueue<T>::dequeue() {
    if (!isEmpty()) {
        queue.erase(queue.begin());  // Remove from the front
    }
}

template <typename T>
T MyQueue<T>::front() const {
    if (!isEmpty()) {
        return queue.front();  // Return the front element
    }
    throw std::out_of_range("Queue is empty");
}

template <typename T>
bool MyQueue<T>::isEmpty() const {
    return queue.empty();  // Check if the queue is empty
}

template <typename T>
size_t MyQueue<T>::size() const {
    return queue.size();  // Return the size of the queue
}
