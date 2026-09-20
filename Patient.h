#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

// Severity used by the Emergency Priority Queue.
// Higher number = more urgent.
enum class Severity {
    LOW = 1,
    MEDIUM = 2,
    HIGH = 3,
    CRITICAL = 4
};

class Patient : public Person {
private:
    std::string diagnosis;
    Severity severity;
    bool admitted;
    int assignedDoctorId; // -1 if not yet assigned

public:
    Patient(int id, const std::string& name, int age,
            const std::string& diagnosis = "Not yet diagnosed",
            Severity severity = Severity::LOW);

    std::string getDiagnosis() const { return diagnosis; }
    void setDiagnosis(const std::string& d) { diagnosis = d; }

    Severity getSeverity() const { return severity; }
    void setSeverity(Severity s) { severity = s; }

    bool isAdmitted() const { return admitted; }
    void admit() { admitted = true; }
    void discharge() { admitted = false; }

    int getAssignedDoctorId() const { return assignedDoctorId; }
    void assignDoctor(int doctorId) { assignedDoctorId = doctorId; }

    void display() const override;
};

#endif // PATIENT_H
