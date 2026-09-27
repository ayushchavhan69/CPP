#include <iostream>  // For input and output

// Base class
class Base
{
public:
    // Display base class message
    void display() const
    {
        std::cout << "Base display function\n";
    }
};

// Derived class
class Derived : public Base
{
public:
    // Display derived class message
    void display() const
    {
        std::cout << "Derived display function\n";
    }
};

int main()
{
    // Create object of Derived class
    Derived derivedObject;

    // Base pointer pointing to Derived object
    Base* basePointer = &derivedObject;

    // Call function using Base pointer
    std::cout << "Call via Base pointer: ";
    basePointer->display();

    // Call function using Derived object
    std::cout << "Direct call on Derived object: ";
    derivedObject.display();

    return 0;
}