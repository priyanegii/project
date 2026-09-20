#ifndef PERSON_H
#define PERSON_H

#include <string>

// Abstract base class for anyone in the hospital system.
// Patient, Doctor, and Staff all derive from this.
class Person {
protected:
    int id;
    std::string name;
    int age;

public:
    Person(int id, const std::string& name, int age)
        : id(id), name(name), age(age) {}

    virtual ~Person() {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // Every subclass must define how it displays itself.
    virtual void display() const = 0;
};

#endif // PERSON_H
