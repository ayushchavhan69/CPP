#include <iostream>  // For input and output
#include <string>    // For using string
#include <utility>   // For using move()

// Base class
class Employee
{
protected:
    std::string name;  // Employee name

public:
    // Constructor to set employee name
    explicit Employee(std::string employeeName) : name(std::move(employeeName)) {}
};

// Derived class
class Developer : public Employee
{
private:
    std::string language;  // Programming language

public:
    // Constructor to set name and language
    Developer(std::string employeeName, std::string programmingLanguage)
        : Employee(std::move(employeeName)), language(std::move(programmingLanguage)) {}

    // Display developer details
    void display() const
    {
        std::cout << "Developer: " << name << '\n';  // Print name
        std::cout << "Language: " << language << '\n';  // Print language
    }
};

int main()
{
    // Create developer object
    Developer developer("Neha", "C++");

    // Display details
    developer.display();

    return 0;
}