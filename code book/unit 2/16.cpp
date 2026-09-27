#include <iostream>  // For input and output
#include <string>    // For using string
#include <utility>   // For using move()

// Base class
class Employee
{
protected:
    int employeeId;       // Stores employee ID
    std::string name;     // Stores employee name

public:
    // Constructor to set employee details
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function to calculate salary
    virtual double calculateSalary() const = 0;

    // Display basic employee details
    void displayBasicDetails() const
    {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

// Derived class for permanent employees
class PermanentEmployee : public Employee
{
private:
    double basicSalary;  // Stores basic salary
    double allowance;    // Stores extra allowance

public:
    // Constructor to set permanent employee details
    PermanentEmployee(int id, std::string employeeName, double basic, double extra)
        : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}

    // Calculate permanent employee salary
    double calculateSalary() const override
    {
        return basicSalary + allowance;
    }
};

// Derived class for contract employees
class ContractEmployee : public Employee
{
private:
    double hourlyRate;  // Stores payment per hour
    int hoursWorked;    // Stores total working hours

public:
    // Constructor to set contract employee details
    ContractEmployee(int id, std::string employeeName, double rate, int hours)
        : Employee(id, std::move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}

    // Calculate contract employee salary
    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }
};

// Function to display employee payslip
void displayPaySlip(const Employee &employee)
{
    employee.displayBasicDetails();  // Display employee details
    std::cout << "Salary: " << employee.calculateSalary() << "\n\n";
}

int main()
{
    // Create permanent and contract employee objects
    PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);
    ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

    // Display payslips
    displayPaySlip(permanentEmployee);
    displayPaySlip(contractEmployee);

    return 0;
}