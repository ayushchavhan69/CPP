#include <iostream>  // For input and output

// Base class
class Base
{
public:
    // Constructor of Base class
    Base()
    {
        std::cout << "Base constructor\n";
    }

    // Destructor of Base class
    ~Base()
    {
        std::cout << "Base destructor\n";
    }
};

// Derived class inheriting from Base
class Derived : public Base
{
public:
    // Constructor of Derived class
    Derived()
    {
        std::cout << "Derived constructor\n";
    }

    // Destructor of Derived class
    ~Derived()
    {
        std::cout << "Derived destructor\n";
    }
};

int main()
{
    // Create object of Derived class
    Derived object;

    return 0;  // Object is destroyed automatically
}