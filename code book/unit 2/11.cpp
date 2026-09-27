#include <iostream>  // For input and output

// Abstract base class
class Shape
{
public:
    // Pure virtual function
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

// Derived class Rectangle
class Rectangle : public Shape
{
private:
    double length;  // Stores rectangle length
    double width;   // Stores rectangle width

public:
    // Constructor to set length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Calculate rectangle area
    double area() const override
    {
        return length * width;
    }
};

// Derived class Circle
class Circle : public Shape
{
private:
    double radius;  // Stores circle radius

public:
    // Constructor to set radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Calculate circle area
    double area() const override
    {
        return 3.141592653589793 * radius * radius;
    }
};

int main()
{
    // Create Rectangle and Circle objects
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.0);

    // Display areas
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';
    std::cout << "Circle Area: " << circle.area() << '\n';

    return 0;
}