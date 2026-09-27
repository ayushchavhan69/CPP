#include <iostream>  // For input and output

// Account class
class Account
{
private:
    double balance;  // Stores account balance

    friend class Auditor;  // Allows Auditor to access private members

public:
    // Constructor to set initial balance
    explicit Account(double initialBalance) : balance(initialBalance) {}
};

// Auditor class
class Auditor
{
public:
    // Function to check account balance
    void inspect(const Account &account) const
    {
        std::cout << "Account Balance: " << account.balance << '\n';
    }
};

int main()
{
    // Create Account object
    Account account(5000.0);

    // Create Auditor object
    Auditor auditor;

    // Display account balance
    auditor.inspect(account);

    return 0;
}