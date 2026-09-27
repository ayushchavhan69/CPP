#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function to calculate area
    virtual double area() const {
        return 0.0;
    }

    // Virtual destructor
    virtual ~Shape() = default;
};

// Rectangle class inherits from Shape
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Calculate area of rectangle
    double area() const override {
        return length * width;
    }
};

// Circle class inherits from Shape
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Calculate area of circle
    double area() const override {
        constexpr double PI = 3.141592653589793;
        return PI * radius * radius;
    }
};

// Function to display the area of any shape
void printArea(const Shape& shape) {
    cout << "Area: " << shape.area() << '\n';
}

int main() {
    // Create Rectangle and Circle objects
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.0);

    // Display areas using the same function
    printArea(rectangle);
    printArea(circle);

    return 0;
}