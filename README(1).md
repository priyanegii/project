# Care-Pulse
### An Integrated Smart Healthcare System

Care-Pulse is a C++-based Hospital Management System designed to organize and manage the major operational processes of a hospital through a unified system.

The system combines Data Structures & Algorithms (DSA) and Object-Oriented Programming (OOP) to efficiently manage patients, doctors, appointments, OPD queues, emergency cases, admissions, wards, rooms, beds, billing, and discharge.

Care-Pulse is designed around the complete patient journey, from registration and consultation to admission, treatment, billing, and discharge, while maintaining organized and persistent records.

> **Team:** CodeForgers (Team # DSCPP-III-2026-T033) — Data Structures and Object-Oriented Programming, Graphic Era (Deemed to be University), Dehradun

## Project Overview

A hospital consists of multiple interconnected processes that need to work together efficiently. Patient registration, OPD management, emergency handling, doctor assignment, admission, bed allocation, billing, and discharge are all dependent on accurate and timely information.

Care-Pulse brings these processes together into a centralized hospital management system.

The system provides different data structures for different operational requirements. Regular OPD patients are handled using a Queue, emergency patients are prioritized using a Priority Queue, patient records can be searched using a Binary Search Tree, and doctor information can be accessed efficiently using a Hash Table.

The overall patient workflow is:

```
Patient Registration
        ↓
   OPD / Emergency
        ↓
 Doctor Consultation
        ↓
 Admission Required?
     ↙       ↘
   No         Yes
   ↓           ↓
Treatment   Ward / Room / Bed Allocation
   ↓           ↓
   └────── Treatment
             ↓
           Billing
             ↓
          Discharge
             ↓
      Record Persistence
```

## Current Implementation Status

Care-Pulse is under active development (Phase-II of a course project). Status below reflects what's actually implemented in this repository right now, not the full target design.

| Component | Status |
|---|---|
| `Person` base class, `Patient` / `Doctor` / `Staff` subclasses | Completed |
| Linked List (active patients) | Completed |
| Queue (OPD, FIFO) | Completed |
| Stack (undo last action) | Completed |
| Priority Queue (emergency triage) | In progress |
| Binary Search Tree (patient ID search) | Planned |
| Hash Table (doctor lookup) | Planned |
| Ward / Room / Bed allocation | Planned |
| Billing module | Planned |
| File-based persistence | Planned |
| React-based Care-Pulse tracker | Static skeleton only, not yet connected |

## Objectives

Care-Pulse is designed to:

- Centralize major hospital management operations.
- Maintain organized patient and doctor records.
- Manage OPD patients using First-In-First-Out (FIFO) processing.
- Prioritize emergency patients according to severity.
- Provide efficient patient searching.
- Provide fast doctor information lookup.
- Manage hospital wards, rooms, and beds.
- Track doctor availability and assignments.
- Manage appointments and consultations.
- Generate itemized patient bills.
- Process patient discharge.
- Maintain records between different executions of the system.
- Demonstrate efficient use of custom Data Structures and Object-Oriented Programming, without relying on STL containers for the core DSA layer.

## Core Features

### Patient Management

Care-Pulse provides a centralized mechanism for managing patient information, including patient ID, name, age, diagnosis, severity, assigned doctor, and admission status. Patient records can be searched efficiently once the search structure (BST) is in place.

### OPD Management

The OPD module manages patients waiting for consultation. Patients entering the OPD are placed into a Queue and processed according to the FIFO principle:

```
Front
  ↓
[P1] [P2] [P3] [P4]
                    ↑
                   Rear
```

### Emergency Management

Emergency cases require a different processing strategy from normal OPD cases. Care-Pulse uses a Priority Queue to prioritize emergency patients according to their severity:

```
Critical   → Highest Priority
Severe     → High Priority
Moderate   → Medium Priority
Stable     → Lower Priority
```

An emergency patient with higher severity is handled before a lower-severity case even if they arrived later.

### Doctor Management

Maintains doctor ID, name, specialization, availability, and assigned patients. Doctor lookup will be supported using a Hash Table for efficient access.

### Doctor Assignment

```
Patient
   ↓
OPD / Emergency
   ↓
Doctor Availability
   ↓
Doctor Assignment
   ↓
Consultation
```

### Ward, Room and Bed Management

For patients requiring admission, Care-Pulse manages hospital resources through a hierarchy:

```
Ward
  ↓
Room
  ↓
Bed
```

### Billing Management

Itemized billing per patient (consultation, room/bed charges, treatment charges, other services, total amount).

### Discharge Management

```
Treatment Completed
        ↓
    Final Bill
        ↓
     Discharge
        ↓
   Release Bed
        ↓
Update Availability
        ↓
Record Persistence
```

## Data Structures

All core data structures are implemented from scratch (no STL containers).

| Data Structure | Hospital Application | Status |
|---|---|---|
| Linked List | Dynamic active-patient record management | Completed |
| Queue | OPD patient management (FIFO) | Completed |
| Stack | Undo of recent operations | Completed |
| Priority Queue | Emergency patient prioritization | In progress |
| Binary Search Tree | Patient record searching | Planned |
| Hash Table | Doctor information lookup | Planned |

## Object-Oriented Design

```
                 Person
                /      \
               /        \
          Patient      Doctor
               
                Staff
```

- **Encapsulation** — each hospital entity manages its own data and behavior.
- **Inheritance** — `Patient`, `Doctor`, and `Staff` derive from a common `Person` base class.
- **Abstraction** — the Hospital Controller manages patient flow without exposing internal data-structure implementation.
- **Polymorphism** — `display()` is defined once at the `Person` level and overridden per entity type.

## System Architecture

```
              User / Staff Input
                     │
                     ↓
          ┌─────────────────────┐
          │ Hospital Controller  │
          └──────────┬──────────┘
                     │
          ┌──────────┼──────────┐
          ↓          ↓          ↓
       Patient     Doctor     Admission
       Module      Module      Module
          │          │          │
          └──────────┼──────────┘
                     ↓
          ┌─────────────────────┐
          │    Custom DSA       │
          │      Engine         │
          └──────────┬──────────┘
                     │
       ┌─────────────┼─────────────┐
       ↓             ↓             ↓
    Queue       Priority Queue     BST
       │             │             │
      OPD         Emergency       Patients
                     │
                     ↓
                Hash Table
                     │
                   Doctors
                     │
                     ↓
             File Persistence
```

## Technology

- **Language:** C++ (C++17)
- **Paradigms:** OOP + custom DSA (no STL containers for core logic)
- **Data Storage:** File-based persistence (planned)
- **Development Environment:** Visual Studio Code
- **Version Control:** Git and GitHub

## Project Structure

```
project/
└── carepulse/
    ├── src/
    │   ├── Person.h            # Abstract base class
    │   ├── Patient.h / .cpp    # Patient entity
    │   ├── Doctor.h / .cpp     # Doctor entity
    │   ├── Staff.h / .cpp      # Staff entity
    │   ├── LinkedList.h        # Custom linked list
    │   ├── Queue.h             # Custom FIFO queue
    │   ├── Stack.h             # Custom stack (undo)
    │   ├── PriorityQueue.h     # Custom priority queue (emergency)
    │   └── main.cpp            # Demo program
    ├── tests/
    │   └── tests.cpp           # Basic tests
    ├── README.md
    └── .gitignore
```

Planned additions: `BST.h`, `HashTable.h`, `Ward.h`/`Room.h`/`Bed.h`, `Bill.h`, and a file-persistence module, plus a `client/` directory for the React tracker.

## Requirements

- A C++17-capable compiler (e.g. g++)
- Visual Studio Code or another C++ development environment
- Git

## Running the System

```bash
git clone https://github.com/priyanegii/project.git
cd project/carepulse

# Run the demo
g++ -std=c++17 -Wall src/main.cpp src/Patient.cpp src/Doctor.cpp src/Staff.cpp -o carepulse_demo
./carepulse_demo

# Run the tests
g++ -std=c++17 -Wall tests/tests.cpp -o tests/tests_bin
./tests/tests_bin
```

## Development Roadmap

**Phase 1 — System Design** (Completed)
- Define hospital workflow, system architecture, major entities, DSA-to-operation mapping, OOP class hierarchy.

**Phase 2 — Core Development** (Current phase)
- Done: Person/Patient/Doctor/Staff classes, Linked List, Queue, Stack
- In progress: Priority Queue
- Planned: BST, Hash Table, Hospital Controller, file persistence

**Phase 3 — System Integration**
- Integrate patient/doctor modules, OPD/emergency processing, admission and bed allocation, billing, discharge — all coordinated through the Hospital Controller.

**Phase 4 — Testing and Refinement**
- Module testing, full patient-workflow testing, edge cases, data-consistency validation, performance refinement.

## Future Scope

- Database-backed storage
- Role-based access control
- Advanced hospital analytics and reporting
- Multiple hospital/branch management
- Pharmacy, inventory, and laboratory management
- Insurance and payment integration
- Cloud-based deployment

## Design Principles

- **Modularity** — each hospital operation is a separate logical module.
- **Efficiency** — data structures chosen to fit each operation's needs.
- **Maintainability** — OOP keeps data and functionality organized.
- **Extensibility** — new modules can be added without reworking the core.
- **Data Consistency** — the Hospital Controller coordinates all cross-module changes.

## Project Status

**Current Status:** In active development (Phase-II).

The system architecture, hospital workflow, DSA mapping, and OOP design form the foundation of the system. The Person hierarchy, Linked List, Queue, and Stack are implemented and tested; the Priority Queue, BST, Hash Table, and remaining modules are being implemented progressively.

## Team

| Name | Role | Primary Contribution |
|---|---|---|
| Dishita Gairola | Team Lead | System workflow, architecture & DSA mapping |
| Priya Negi | Member | Person hierarchy, Stack, Priority Queue |
| Tanmay Kulshrestha | Member | Linked List, Queue |
| Siddharth Dangi | Member | Repository setup, documentation, React tracker |

## Repository

[github.com/priyanegii/project](https://github.com/priyanegii/project)

## License

This project is intended for academic development, demonstration, and course evaluation purposes.
