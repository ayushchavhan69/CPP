#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double area() const = 0;

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

// Triangle class inherits from Shape
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    // Constructor to initialize base and height
    Triangle(double b, double h) : base(b), height(h) {}

    // Calculate area of triangle
    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    // Create Rectangle and Triangle objects
    Rectangle rectangle(8.0, 4.0);
    Triangle triangle(6.0, 3.0);

    // Display the areas
    cout << "Rectangle Area: " << rectangle.area() << '\n';
    cout << "Triangle Area: " << triangle.area() << '\n';

    return 0;
}