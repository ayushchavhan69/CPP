#include <iostream>  // For input and output operations
#include <string>    // For using string data type
#include <utility>   // For using std::move

// Base class
class Person
{
protected:
    std::string name;  // Stores the person's name

public:
    // Constructor to initialize the person's name
    explicit Person(std::string personName) : name(std::move(personName)) {}

    // Function to display the person's name
    void displayName() const
    {
        std::cout << "Name: " << name << '\n';
    }
};

// Derived class inheriting from Person
class Student : public Person
{
private:
    int rollNumber;  // Stores the student's roll number

public:
    // Constructor to initialize name and roll number
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {}

    // Function to display student details
    void displayStudent() const
    {
        displayName();  // Calls the base class function
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Main function: execution starts here
int main()
{
    // Creating an object of the Student class
    Student student("Amit", 101);

    // Calling the function to display student details
    student.displayStudent();

    return 0;  // Indicates successful program execution
}