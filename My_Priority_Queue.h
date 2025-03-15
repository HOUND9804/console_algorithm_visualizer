#ifndef MY_PRIORITY_QUEUE_H
#define MY_PRIORITY_QUEUE_H

template <typename T, unsigned long MAX_SIZE = 1000>
class My_Priority_Queue {
public:
    My_Priority_Queue() : heap_size(0) {}

    void push(const T& value) {
        if (heap_size >= MAX_SIZE) return;

        heap[heap_size] = value;
        unsigned long index = heap_size;
        heap_size++;

        while (index > 0) {
            unsigned long parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                T temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (heap_size == 0) return;

        heap[0] = heap[heap_size - 1];
        heap_size--;

        unsigned long index = 0;
        while (index * 2 + 1 < heap_size) {
            unsigned long left_child = index * 2 + 1;
            unsigned long right_child = index * 2 + 2;
            unsigned long smallest = index;

            if (left_child < heap_size && heap[left_child] < heap[smallest]) {
                smallest = left_child;
            }
            if (right_child < heap_size && heap[right_child] < heap[smallest]) {
                smallest = right_child;
            }
            if (smallest != index) {
                T temp = heap[index];
                heap[index] = heap[smallest];
                heap[smallest] = temp;
                index = smallest;
            } else {
                break;
            }
        }
    }

    const T& top() const {
        return heap[0];
    }

    bool empty() const {
        return heap_size == 0;
    }

    unsigned long size() const {
        return heap_size;
    }

private:
    T heap[MAX_SIZE];
    unsigned long heap_size;
};

#endif // MY_PRIORITY_QUEUE_H








