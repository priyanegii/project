#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <functional>

// A minimal singly linked list built from scratch (no std::list).
// Used to hold the hospital's active patients.
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    ~LinkedList() {
        clear();
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
        count++;
    }

    // Removes the first node for which matches(value) is true.
    // Returns true if something was removed.
    bool removeIf(const std::function<bool(const T&)>& matches) {
        Node* cur = head;
        Node* prev = nullptr;
        while (cur) {
            if (matches(cur->data)) {
                if (prev) prev->next = cur->next;
                else head = cur->next;
                delete cur;
                count--;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    // Returns a pointer to the first matching element, or nullptr.
    T* find(const std::function<bool(const T&)>& matches) {
        Node* cur = head;
        while (cur) {
            if (matches(cur->data)) return &cur->data;
            cur = cur->next;
        }
        return nullptr;
    }

    void forEach(const std::function<void(const T&)>& fn) const {
        Node* cur = head;
        while (cur) {
            fn(cur->data);
            cur = cur->next;
        }
    }

    int size() const { return count; }
    bool isEmpty() const { return head == nullptr; }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* toDelete = cur;
            cur = cur->next;
            delete toDelete;
        }
        head = nullptr;
        count = 0;
    }
};

#endif // LINKEDLIST_H
