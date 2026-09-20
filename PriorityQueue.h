#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdexcept>
#include <functional>

// A minimal priority queue built from scratch (no std::priority_queue).
// Inserts keep the list ordered by priority so the most urgent
// emergency case is always at the front. A comparator is passed in
// at construction time, so severity rules live outside this class.
template <typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
        Node(const T& value, int p) : data(value), priority(p), next(nullptr) {}
    };

    Node* head;
    int count;

public:
    PriorityQueue() : head(nullptr), count(0) {}

    ~PriorityQueue() {
        while (!isEmpty()) extractMax();
    }

    // Higher priority value = more urgent = served first.
    void insert(const T& value, int priority) {
        Node* newNode = new Node(value, priority);
        if (!head || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next && cur->next->priority >= priority) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
        count++;
    }

    T extractMax() {
        if (isEmpty()) throw std::runtime_error("Priority queue is empty");
        Node* toDelete = head;
        T value = toDelete->data;
        head = head->next;
        delete toDelete;
        count--;
        return value;
    }

    T peek() const {
        if (isEmpty()) throw std::runtime_error("Priority queue is empty");
        return head->data;
    }

    bool isEmpty() const { return head == nullptr; }
    int size() const { return count; }
};

#endif // PRIORITYQUEUE_H
