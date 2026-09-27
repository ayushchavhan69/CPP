#include <iostream>
using namespace std;

// Base class
class Base {
public:
    // Virtual function
    virtual void display() const {
        cout << "Base object\n";
    }

    // Virtual destructor
    virtual ~Base() = default;
};

// Derived class inherits from Base
class Derived : public Base {
public:
    // Override the base class display function
    void display() const override {
        cout << "Derived object\n";
    }
};

// Function receives object by value
void displayByValue(Base object) {
    object.display();
}

// Function receives object by reference
void displayByReference(const Base& object) {
    object.display();
}

// Function receives object by pointer
void displayByPointer(const Base* object) {
    // Check that pointer is not null
    if (object) {
        object->display();
    }
}

int main() {
    // Create an object of Derived class
    Derived derived;

    cout << "Passing by value: ";
    displayByValue(derived);

    cout << "Passing by reference: ";
    displayByReference(derived);

    cout << "Passing by pointer: ";
    displayByPointer(&derived);

    return 0;
}
