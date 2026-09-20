#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

// A minimal FIFO queue built from scratch (no std::queue).
// Used for OPD waiting: first patient in, first patient seen.
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front_;
    Node* back_;
    int count;

public:
    Queue() : front_(nullptr), back_(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) dequeue();
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (!back_) {
            front_ = back_ = newNode;
        } else {
            back_->next = newNode;
            back_ = newNode;
        }
        count++;
    }

    T dequeue() {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        Node* toDelete = front_;
        T value = toDelete->data;
        front_ = front_->next;
        if (!front_) back_ = nullptr;
        delete toDelete;
        count--;
        return value;
    }

    T peek() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        return front_->data;
    }

    bool isEmpty() const { return front_ == nullptr; }
    int size() const { return count; }
};

#endif // QUEUE_H
