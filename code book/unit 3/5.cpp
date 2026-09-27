#include <iostream>  // For input and output

// Class to store complex numbers
class Complex
{
private:
    int real;       // Stores real part
    int imaginary;  // Stores imaginary part

public:
    // Constructor to set real and imaginary values
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Overload + operator for addition
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overload - operator for subtraction
    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Display complex number
    void display() const
    {
        std::cout << real;

        if (imaginary >= 0)
        {
            std::cout << " + ";
        }
        else
        {
            std::cout << " - ";
        }

        std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
    }
};

int main()
{
    // Create two complex number objects
    Complex first(5, 7);
    Complex second(2, 3);

    // Perform addition and subtraction
    Complex sum = first + second;
    Complex diff = first - second;

    // Display results
    std::cout << "First complex number: ";
    first.display();

    std::cout << "Second complex number: ";
    second.display();

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    diff.display();

    return 0;
}