#include "Doctor.h"
#include <iostream>

Doctor::Doctor(int id, const std::string& name, int age,
               const std::string& specialization)
    : Person(id, name, age), specialization(specialization), available(true) {}

void Doctor::display() const {
    std::cout << "[Doctor] ID: " << id
              << " | Name: " << name
              << " | Specialization: " << specialization
              << " | Available: " << (available ? "Yes" : "No")
              << std::endl;
}
