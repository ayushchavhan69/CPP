#include <iostream>  // For input and output

// Calculate area of square
int calculateArea(int side)
{
    return side * side;
}

// Calculate area of rectangle
int calculateArea(int length, int width)
{
    return length * width;
}

// Calculate area of circle
double calculateArea(double radius)
{
    constexpr double PI = 3.141592653589793;
    return PI * radius * radius;
}

// Calculate area of triangle
double calculateArea(double base, double height)
{
    return 0.5 * base * height;
}

int main()
{
    // Display area of square
    std::cout << "Square Area: " << calculateArea(5) << '\n';

    // Display area of rectangle
    std::cout << "Rectangle Area: " << calculateArea(6, 4) << '\n';

    // Display area of circle
    std::cout << "Circle Area: " << calculateArea(2.0) << '\n';

    // Display area of triangle
    std::cout << "Triangle Area: " << calculateArea(5.0, 8.0) << '\n';

    return 0;
}