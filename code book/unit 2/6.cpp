#include <iostream>  // For input and output

// First base class
class Academic
{
protected:
    int academicMarks;  // Stores academic marks

public:
    // Constructor to set academic marks
    explicit Academic(int marks) : academicMarks(marks) {}

    // Display academic marks
    void showAcademic() const
    {
        std::cout << "Academic Marks: " << academicMarks << '\n';
    }
};

// Second base class
class Sports
{
protected:
    int sportsMarks;  // Stores sports marks

public:
    // Constructor to set sports marks
    explicit Sports(int marks) : sportsMarks(marks) {}

    // Display sports marks
    void showSports() const
    {
        std::cout << "Sports Marks: " << sportsMarks << '\n';
    }
};

// Derived class inheriting from both Academic and Sports
class Student : public Academic, public Sports
{
public:
    // Constructor to initialize both base classes
    Student(int academic, int sports)
        : Academic(academic), Sports(sports) {}

    // Calculate and display total marks
    void showTotal() const
    {
        std::cout << "Total Marks: " << academicMarks + sportsMarks << '\n';
    }
};

int main()
{
    // Create student object with academic and sports marks
    Student student(80, 15);

    // Display marks
    student.showAcademic();
    student.showSports();
    student.showTotal();

    return 0;
}