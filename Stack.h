#ifndef STACK_H
#define STACK_H

#include <stdexcept>

// A minimal stack built from scratch (no std::stack).
// Used to remember recent actions so they can be undone.
template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* top_;
    int count;

public:
    Stack() : top_(nullptr), count(0) {}

    ~Stack() {
        while (!isEmpty()) pop();
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = top_;
        top_ = newNode;
        count++;
    }

    T pop() {
        if (isEmpty()) throw std::runtime_error("Stack is empty");
        Node* toDelete = top_;
        T value = toDelete->data;
        top_ = top_->next;
        delete toDelete;
        count--;
        return value;
    }

    T peek() const {
        if (isEmpty()) throw std::runtime_error("Stack is empty");
        return top_->data;
    }

    bool isEmpty() const { return top_ == nullptr; }
    int size() const { return count; }
};

#endif // STACK_H
