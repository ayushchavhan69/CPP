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
};

// Derived class inheriting from Person
class Student : public Person
{
private:
    int rollNumber;  // Stores student's roll number

public:
    // Constructor to set name and roll number
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {}

    // Display student details
    void display() const
    {
        std::cout << "Name: " << name << '\n';
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

int main()
{
    // Create Student object
    Student student("Kiran", 24);

    // Display student details
    student.display();

    return 0;
}