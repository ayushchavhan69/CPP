#include <iostream>  // For input and output

// Base class
class Base
{
public:
    // Function to display a message
    void show() const
    {
        std::cout << "Base public function\n";
    }
};

// Public inheritance
class PublicDerived : public Base
{
    // Base class public members remain public
};

// Private inheritance
class PrivateDerived : private Base
{
public:
    // Function to call the base class function
    void callBaseShow() const
    {
        show();
    }
};

int main()
{
    // Creating object of PublicDerived
    PublicDerived publicObject;
    publicObject.show();  // Calling base class function directly

    // Creating object of PrivateDerived
    PrivateDerived privateObject;
    privateObject.callBaseShow();  // Calling base function through derived class

    // privateObject.show();  // Error: show() is private due to private inheritance

    return 0;
}