#include "Patient.h"
#include <iostream>

Patient::Patient(int id, const std::string& name, int age,
                  const std::string& diagnosis, Severity severity)
    : Person(id, name, age),
      diagnosis(diagnosis),
      severity(severity),
      admitted(false),
      assignedDoctorId(-1) {}

void Patient::display() const {
    std::cout << "[Patient] ID: " << id
              << " | Name: " << name
              << " | Age: " << age
              << " | Diagnosis: " << diagnosis
              << " | Severity: " << static_cast<int>(severity)
              << " | Admitted: " << (admitted ? "Yes" : "No")
              << std::endl;
}
