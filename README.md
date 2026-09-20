# Care-Pulse: An Integrated Smart Healthcare System

**Team:** CodeForgers (Team # DSCPP-III-2026-T033)
**Course:** Data Structures and Object-Oriented Programming, Graphic Era (Deemed to be University), Dehradun

## About

Care-Pulse is a Hospital Management System written in C++ that models the
complete patient journey: registration, OPD waiting, emergency triage,
doctor assignment, admission, billing, and discharge. All underlying data
structures (Linked List, Queue, Priority Queue, Stack, and — coming in a
later milestone — BST and Hash Table) are implemented from scratch,
without relying on STL containers such as `std::list`, `std::queue`,
`std::stack`, or `std::priority_queue`.

The project also demonstrates Object-Oriented Programming through an
abstract `Person` base class, extended by `Patient`, `Doctor`, and `Staff`.

## Project Structure

```
carepulse/
├── src/
│   ├── Person.h            # Abstract base class
│   ├── Patient.h / .cpp    # Patient entity (severity, diagnosis, admission)
│   ├── Doctor.h / .cpp     # Doctor entity (specialization, availability)
│   ├── Staff.h / .cpp      # Staff entity (role)
│   ├── LinkedList.h        # Custom linked list (active patients)
│   ├── Queue.h             # Custom FIFO queue (OPD waiting line)
│   ├── Stack.h             # Custom stack (undo last action)
│   ├── PriorityQueue.h     # Custom priority queue (emergency triage)
│   └── main.cpp            # Demo program wiring everything together
├── tests/
│   └── tests.cpp           # Basic tests for the custom data structures
└── README.md
```

Planned next (Phase-III): BST for patient-ID search, Hash Table for doctor
lookup, Ward/Room/Bed allocation, Bill class, file-based persistence, and
a React-based Care-Pulse tracker connected to the C++ engine.

## Building and Running

Requires a C++17-capable compiler (e.g. g++).

**Run the demo:**
```bash
g++ -std=c++17 -Wall src/main.cpp src/Patient.cpp src/Doctor.cpp src/Staff.cpp -o carepulse_demo
./carepulse_demo
```

**Run the tests:**
```bash
g++ -std=c++17 -Wall tests/tests.cpp -o tests/tests_bin
./tests/tests_bin
```

## Team

| Member | Role |
|---|---|
| Dishita Gairola | Team Lead — system workflow, architecture |
| Priya Negi | Person hierarchy, Stack, Priority Queue |
| Tanmay Kulshrestha | Linked List, Queue |
| Siddharth Dangi | Repository setup, React tracker |

## License

Academic project for course evaluation purposes.
