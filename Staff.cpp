#include "Staff.h"
#include <iostream>

Staff::Staff(int id, const std::string& name, int age, const std::string& role)
    : Person(id, name, age), role(role) {}

void Staff::display() const {
    std::cout << "[Staff] ID: " << id
              << " | Name: " << name
              << " | Role: " << role
              << std::endl;
}
