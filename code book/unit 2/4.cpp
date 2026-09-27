#include <iostream>  // For input and output
#include <string>    // For using string
#include <utility>   // For using move()

// Base class
class Person
{
protected:
    std::string name;  // Stores person's name

public:
    // Constructor to set person's name
    explicit Person(std::string personName) : name(std::move(personName)) {}

    // Display person's name
    void showPerson() const
    {
        std::cout << "Name: " << name << '\n';
    }
};

// Derived class inheriting from Person
class Employee : public Person
{
protected:
    int employeeId;  // Stores employee ID

public:
    // Constructor to set name and employee ID
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)), employeeId(id) {}

    // Display employee ID
    void showEmployee() const
    {
        std::cout << "Employee ID: " << employeeId << '\n';
    }
};

// Derived class inheriting from Employee
class Manager : public Employee
{
private:
    int teamSize;  // Stores number of team members

public:
    // Constructor to set manager details
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), teamSize(size) {}

    // Display complete manager details
    void showManager() const
    {
        showPerson();    // Display name
        showEmployee();  // Display employee ID
        std::cout << "Team Size: " << teamSize << '\n';
    }
};

int main()
{
    // Create manager object
    Manager manager("Ravi", 501, 8);

    // Display manager details
    manager.showManager();

    return 0;
}