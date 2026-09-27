#include <iostream>
using namespace std;

// Base class
class Base {
public:
    // Virtual destructor of base class
    virtual ~Base() {
        cout << "Base destructor\n";
    }
};

// Derived class inherits from Base
class Derived : public Base {
public:
    // Destructor of derived class
    ~Derived() override {
        cout << "Derived destructor\n";
    }
};

int main() {
    // Base class pointer points to Derived object
    Base* pointer = new Derived();

    // Delete the object using base class pointer
    delete pointer;

    return 0;
}
