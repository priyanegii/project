#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"

class Doctor : public Person {
private:
    std::string specialization;
    bool available;

public:
    Doctor(int id, const std::string& name, int age,
           const std::string& specialization);

    std::string getSpecialization() const { return specialization; }
    bool isAvailable() const { return available; }
    void setAvailable(bool status) { available = status; }

    void display() const override;
};

#endif // DOCTOR_H
