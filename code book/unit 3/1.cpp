#include <iostream>  // For input and output
#include <string>    // For using string

// Function to add two integers
int add(int first, int second)
{
    return first + second;
}

// Function to add two decimal numbers
double add(double first, double second)
{
    return first + second;
}

// Function to add three integers
int add(int first, int second, int third)
{
    return first + second + third;
}

// Function to join two strings
std::string add(const std::string& first, const std::string& second)
{
    return first + second;
}

int main()
{
    // Add two integers
    std::cout << "Sum of two integers: " << add(10, 20) << '\n';

    // Add two decimal numbers
    std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';

    // Add three integers
    std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';

    // Join two strings
    std::cout << "Joined strings: "
              << add(std::string("Hello, "), std::string("World!")) << '\n';

    return 0;
}