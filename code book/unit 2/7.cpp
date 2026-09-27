#include <iostream>  // For input and output

// First base class
class Academic
{
public:
    // Display academic information
    void display() const
    {
        std::cout << "Academic information\n";
    }
};

// Second base class
class Sports
{
public:
    // Display sports information
    void display() const
    {
        std::cout << "Sports information\n";
    }
};

// Derived class inheriting from both classes
class Student : public Academic, public Sports
{
public:
    // Display information from both base classes
    void displayAll() const
    {
        Academic::display();  // Call Academic class function
        Sports::display();    // Call Sports class function
    }
};

int main()
{
    // Create Student object
    Student student;

    // Call functions using class name to avoid ambiguity
    student.Academic::display();
    student.Sports::display();

    // Display both information
    student.displayAll();

    return 0;
}