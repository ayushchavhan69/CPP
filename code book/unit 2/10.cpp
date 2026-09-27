#include <iostream>  // For input and output

// Base class
class Vehicle
{
public:
    // Virtual function
    virtual void move() const
    {
        std::cout << "Vehicle is moving\n";
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Derived class Car
class Car : public Vehicle
{
public:
    // Overriding move() function
    void move() const override
    {
        std::cout << "Car moves on roads\n";
    }
};

// Derived class Boat
class Boat : public Vehicle
{
public:
    // Overriding move() function
    void move() const override
    {
        std::cout << "Boat moves on water\n";
    }
};

int main()
{
    // Create objects of Car and Boat
    Car car;
    Boat boat;

    // Call their move() functions
    car.move();
    boat.move();

    return 0;
}