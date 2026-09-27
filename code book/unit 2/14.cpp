#include <iostream>  // For input and output
#include <string>    // For using string
#include <utility>   // For using move()

// Outer class
class University
{
public:
    // Inner class
    class Department
    {
    private:
        std::string name;  // Stores department name

    public:
        // Constructor to set department name
        explicit Department(std::string departmentName)
            : name(std::move(departmentName)) {}

        // Display department name
        void display() const
        {
            std::cout << "Department: " << name << '\n';
        }
    };
};

int main()
{
    // Create object of nested class
    University::Department department("Artificial Intelligence and Data Science");

    // Display department name
    department.display();

    return 0;
}