#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>
using namespace std;

// Abstract base class
class Employee {
protected:
    int employeeId;
    string name;

public:
    // Constructor to initialize employee details
    Employee(int id, string employeeName)
        : employeeId(id), name(move(employeeName)) {}

    // Pure virtual function to calculate salary
    virtual double calculateSalary() const = 0;

    // Display common employee details
    void displayBasicDetails() const {
        cout << "Employee ID: " << employeeId << '\n';
        cout << "Name: " << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

// Permanent employee class
class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;

public:
    // Initialize permanent employee details
    PermanentEmployee(int id, string employeeName, double basic, double extra)
        : Employee(id, move(employeeName)), basicSalary(basic), allowance(extra) {}

    // Calculate salary after deducting 10% tax
    double calculateSalary() const override {
        double gross = basicSalary + allowance;
        double tax = gross * 0.10;
        return gross - tax;
    }
};

// Contract employee class
class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    // Initialize contract employee details
    ContractEmployee(int id, string employeeName, double rate, int hours)
        : Employee(id, move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}

    // Calculate salary based on hours worked
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Freelance employee class
class FreelanceEmployee : public Employee {
private:
    int projectsCompleted;
    double payPerProject;

public:
    // Initialize freelance employee details
    FreelanceEmployee(int id, string employeeName, int projects, double rate)
        : Employee(id, move(employeeName)),
          projectsCompleted(projects), payPerProject(rate) {}

    // Calculate salary based on completed projects
    double calculateSalary() const override {
        return projectsCompleted * payPerProject;
    }
};

int main() {
    // Store different employee objects in one vector
    vector<unique_ptr<Employee>> payroll;

    // Add employees to the payroll
    payroll.push_back(make_unique<PermanentEmployee>(101, "Asha", 40000.0, 8000.0));
    payroll.push_back(make_unique<ContractEmployee>(102, "Vikas", 500.0, 80));
    payroll.push_back(make_unique<FreelanceEmployee>(103, "Rahul", 3, 15000.0));

    double totalPayroll = 0.0;

    // Display details and calculate salary of each employee
    for (const auto& emp : payroll) {
        emp->displayBasicDetails();

        double salary = emp->calculateSalary();
        cout << "Net Salary: Rs. " << salary << "\n\n";

        // Add salary to total company payroll
        totalPayroll += salary;
    }

    // Display total payroll
    cout << "====================================\n";
    cout << "Total Company Payroll: Rs. " << totalPayroll << '\n';
    cout << "====================================\n";

    return 0;
}