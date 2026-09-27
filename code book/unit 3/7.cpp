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

    // Allow friend functions to access private members
    friend Complex operator+(int value, const Complex& number);
    friend Complex operator-(int value, const Complex& number);

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

// Overload + operator for integer and complex number
Complex operator+(int value, const Complex& number)
{
    return Complex(value + number.real, number.imaginary);
}

// Overload - operator for integer and complex number
Complex operator-(int value, const Complex& number)
{
    return Complex(value - number.real, -number.imaginary);
}

int main()
{
    // Create a complex number object
    Complex number(2, 3);

    // Perform addition and subtraction
    Complex resultAdd = 10 + number;
    Complex resultSub = 10 - number;

    // Display results
    std::cout << "10 + (2 + 3i) = ";
    resultAdd.display();

    std::cout << "10 - (2 + 3i) = ";
    resultSub.display();

    return 0;
}