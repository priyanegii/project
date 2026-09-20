#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

class Staff : public Person {
private:
    std::string role; // e.g. "Nurse", "Receptionist", "Billing Clerk"

public:
    Staff(int id, const std::string& name, int age, const std::string& role);

    std::string getRole() const { return role; }

    void display() const override;
};

#endif // STAFF_H
