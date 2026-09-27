#include <iostream>  // For input and output
#include <string>    // For using string
#include <utility>   // For using move()

// Base class
class Vehicle
{
protected:
    std::string registrationNumber;  // Stores vehicle number
    double ratePerDay;               // Stores rent per day

public:
    // Constructor to set vehicle details
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {}

    // Calculate rent for given days
    virtual double calculateRent(int days) const
    {
        return ratePerDay * days;
    }

    // Display vehicle details
    virtual void display() const
    {
        std::cout << "Registration: " << registrationNumber << '\n';
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Derived class Car
class Car : public Vehicle
{
private:
    int numberOfDoors;  // Stores number of doors

public:
    // Constructor to set car details
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate), numberOfDoors(doors) {}

    // Display car details
    void display() const override
    {
        Vehicle::display();  // Display common vehicle details
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

// Derived class Bike
class Bike : public Vehicle
{
private:
    int engineCapacity;  // Stores engine capacity

public:
    // Constructor to set bike details
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate), engineCapacity(capacity) {}

    // Calculate bike rent with 10% discount
    double calculateRent(int days) const override
    {
        return ratePerDay * days * 0.9;
    }

    // Display bike details
    void display() const override
    {
        Vehicle::display();  // Display common vehicle details
        std::cout << "Engine Capacity: " << engineCapacity << " cc\n";
    }
};

int main()
{
    // Create Car and Bike objects
    Car car("MH12AB1234", 2000.0, 5);
    Bike bike("MH12CD5678", 800.0, 150);

    // Display car details and rent
    std::cout << "Car Details\n";
    car.display();
    std::cout << "Rent for 3 days: " << car.calculateRent(3) << "\n\n";

    // Display bike details and rent
    std::cout << "Bike Details\n";
    bike.display();
    std::cout << "Rent for 3 days: " << bike.calculateRent(3) << '\n';

    return 0;
}