#include <iostream>  // For input and output

// Class to store balance
class Balance
{
private:
    double amount;  // Stores balance amount

public:
    // Constructor to set balance
    explicit Balance(double value) : amount(value) {}

    // Overload unary minus (-) operator
    Balance operator-() const
    {
        return Balance(-amount);
    }

    // Display balance
    void display() const
    {
        std::cout << "Rs. " << amount << '\n';
    }
};

int main()
{
    // Create balance object
    Balance currentBalance(5000.50);

    // Apply unary minus operator
    Balance negativeBalance = -currentBalance;

    // Display original balance
    std::cout << "Original Balance: ";
    currentBalance.display();

    // Display negative balance
    std::cout << "Negated Balance: ";
    negativeBalance.display();

    return 0;
}