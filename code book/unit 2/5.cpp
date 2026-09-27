#include <iostream>  // For input and output
#include <string>    // For using string
#include <utility>   // For using move()

// Base class
class Vehicle
{
protected:
    std::string registrationNumber;  // Stores vehicle number

public:
    // Constructor to set registration number
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {}

    // Function to start the vehicle
    void start() const
    {
        std::cout << "Vehicle " << registrationNumber << " started\n";
    }
};

// Derived class Car
class Car : public Vehicle
{
public:
    // Constructor to set car registration number
    explicit Car(std::string registration) : Vehicle(std::move(registration)) {}

    // Function to open car boot
    void openBoot() const
    {
        std::cout << "Car boot opened\n";
    }
};

// Derived class Bike
class Bike : public Vehicle
{
public:
    // Constructor to set bike registration number
    explicit Bike(std::string registration) : Vehicle(std::move(registration)) {}

    // Function to display helmet reminder
    void helmetReminder() const
    {
        std::cout << "Please wear a helmet\n";
    }
};

int main()
{
    // Create objects of Car and Bike
    Car car("MH12AB1234");
    Bike bike("MH12CD5678");

    // Display car details
    car.start();
    car.openBoot();

    // Display bike details
    bike.start();
    bike.helmetReminder();

    return 0;
}