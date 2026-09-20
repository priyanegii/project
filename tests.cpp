// Simple assert-based tests for the custom data structures.
// No test framework required -- run with: g++ tests/tests.cpp -Isrc -o tests/tests && ./tests/tests

#include <cassert>
#include <iostream>

#include "../src/LinkedList.h"
#include "../src/Queue.h"
#include "../src/Stack.h"
#include "../src/PriorityQueue.h"

void testLinkedList() {
    LinkedList<int> list;
    assert(list.isEmpty());

    list.insert(10);
    list.insert(20);
    list.insert(30);
    assert(list.size() == 3);

    int* found = list.find([](const int& v) { return v == 20; });
    assert(found != nullptr && *found == 20);

    bool removed = list.removeIf([](const int& v) { return v == 20; });
    assert(removed);
    assert(list.size() == 2);

    std::cout << "LinkedList tests passed.\n";
}

void testQueue() {
    Queue<int> q;
    assert(q.isEmpty());

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    assert(q.size() == 3);
    assert(q.peek() == 1);

    assert(q.dequeue() == 1); // FIFO order
    assert(q.dequeue() == 2);
    assert(q.size() == 1);

    std::cout << "Queue tests passed.\n";
}

void testStack() {
    Stack<int> s;
    assert(s.isEmpty());

    s.push(1);
    s.push(2);
    s.push(3);
    assert(s.size() == 3);
    assert(s.peek() == 3);

    assert(s.pop() == 3); // LIFO order (undo most recent first)
    assert(s.pop() == 2);
    assert(s.size() == 1);

    std::cout << "Stack tests passed.\n";
}

void testPriorityQueue() {
    PriorityQueue<std::string> pq;
    pq.insert("low-severity patient", 1);
    pq.insert("critical patient", 4);
    pq.insert("medium-severity patient", 2);

    assert(pq.extractMax() == "critical patient");
    assert(pq.extractMax() == "medium-severity patient");
    assert(pq.extractMax() == "low-severity patient");
    assert(pq.isEmpty());

    std::cout << "PriorityQueue tests passed.\n";
}

int main() {
    testLinkedList();
    testQueue();
    testStack();
    testPriorityQueue();
    std::cout << "\nAll tests passed.\n";
    return 0;
}
