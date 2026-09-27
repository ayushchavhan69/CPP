#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double area() const = 0;

    // Pure virtual function to display shape name
    virtual void displayName() const = 0;

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

    // Calculate rectangle area
    double area() const override {
        return length * width;
    }

    // Display shape name
    void displayName() const override {
        cout << "Rectangle";
    }
};

// Circle class inherits from Shape
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Calculate circle area
    double area() const override {
        constexpr double PI = 3.141592653589793;
        return PI * radius * radius;
    }

    // Display shape name
    void displayName() const override {
        cout << "Circle";
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

    // Calculate triangle area
    double area() const override {
        return 0.5 * base * height;
    }

    // Display shape name
    void displayName() const override {
        cout << "Triangle";
    }
};

int main() {
    // Create a vector to store different shapes
    vector<unique_ptr<Shape>> shapes;

    // Add shape objects to the vector
    shapes.push_back(make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(make_unique<Circle>(2.0));
    shapes.push_back(make_unique<Triangle>(4.0, 6.0));

    // Display the name and area of each shape
    for (const auto& shape : shapes) {
        shape->displayName();
        cout << " Area: " << shape->area() << '\n';
    }

    return 0;
}
