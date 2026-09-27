#include <iostream>  // For input and output
#include <string>    // For using string
#include <utility>   // For using move()

// Base class
class Person
{
protected:
    std::string name;  // Stores person's name

public:
    // Constructor to set person's name
    explicit Person(std::string personName) : name(std::move(personName)) {}

    // Display person's name
    void displayName() const
    {
        std::cout << "Name: " << name << '\n';
    }
};

// Student class virtually inherits Person
class Student : virtual public Person
{
public:
    // Constructor of Student
    Student() : Person("Unknown") {}
};

// Employee class virtually inherits Person
class Employee : virtual public Person
{
public:
    // Constructor of Employee
    Employee() : Person("Unknown") {}
};

// TeachingAssistant inherits from Student and Employee
class TeachingAssistant : public Student, public Employee
{
public:
    // Constructor to set assistant's name
    explicit TeachingAssistant(std::string assistantName)
        : Person(std::move(assistantName)), Student(), Employee() {}
};

int main()
{
    // Create TeachingAssistant object
    TeachingAssistant assistant("Riya");

    // Display assistant's name
    assistant.displayName();

    return 0;
}