#include <iostream>
#include <string>

#include "Patient.h"
#include "Doctor.h"
#include "Staff.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "PriorityQueue.h"

// A tiny record of an action, so the Stack can support "undo".
struct Action {
    std::string description;
};

int main() {
    std::cout << "===== Care-Pulse Hospital Management System =====\n\n";

    // ---- Active patients: custom Linked List ----
    LinkedList<Patient> activePatients;

    // ---- OPD waiting line: custom Queue (FIFO) ----
    Queue<int> opdQueue; // stores patient IDs

    // ---- Emergency cases: custom Priority Queue ----
    PriorityQueue<int> emergencyQueue; // stores patient IDs, ranked by severity

    // ---- Recent actions: custom Stack (for undo) ----
    Stack<Action> actionHistory;

    // Register a few patients
    Patient p1(101, "Anil Sharma", 45, "Fever", Severity::LOW);
    Patient p2(102, "Meena Rawat", 62, "Chest pain", Severity::CRITICAL);
    Patient p3(103, "Farid Khan", 30, "Sprained ankle", Severity::MEDIUM);

    activePatients.insert(p1);
    activePatients.insert(p2);
    activePatients.insert(p3);
    actionHistory.push({"Registered patient 101"});
    actionHistory.push({"Registered patient 102"});
    actionHistory.push({"Registered patient 103"});

    // Route: p1 and p3 go to the normal OPD queue, p2 goes to Emergency
    opdQueue.enqueue(p1.getId());
    opdQueue.enqueue(p3.getId());
    emergencyQueue.insert(p2.getId(), static_cast<int>(p2.getSeverity()));
    actionHistory.push({"Routed 101 and 103 to OPD, 102 to Emergency"});

    std::cout << "-- Active patients --\n";
    activePatients.forEach([](const Patient& p) { p.display(); });

    std::cout << "\n-- Emergency queue (most urgent first) --\n";
    while (!emergencyQueue.isEmpty()) {
        int id = emergencyQueue.extractMax();
        std::cout << "Attending to emergency patient ID: " << id << std::endl;
    }

    std::cout << "\n-- OPD queue (FIFO order) --\n";
    while (!opdQueue.isEmpty()) {
        int id = opdQueue.dequeue();
        std::cout << "Calling OPD patient ID: " << id << std::endl;
    }

    // Assign a doctor and demonstrate undo
    Doctor d1(201, "Dr. Kavita Rao", 40, "Cardiology");
    d1.display();

    if (Patient* found = activePatients.find(
            [](const Patient& p) { return p.getId() == 102; })) {
        found->assignDoctor(d1.getId());
        actionHistory.push({"Assigned doctor 201 to patient 102"});
        std::cout << "\nAssigned " << d1.getName()
                  << " to patient ID " << found->getId() << std::endl;
    }

    std::cout << "\n-- Undo last action --\n";
    Action last = actionHistory.pop();
    std::cout << "Undoing: " << last.description << std::endl;

    return 0;
}
