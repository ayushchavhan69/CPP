#include <iostream>
using namespace std;

// Abstract base class
class Payment {
public:
    // Pure virtual function for making payment
    virtual void pay(double amount) const = 0;

    // Virtual destructor
    virtual ~Payment() = default;
};

// Card payment class
class CardPayment : public Payment {
public:
    // Display card payment details
    void pay(double amount) const override {
        cout << "Paid Rs. " << amount << " using card\n";
    }
};

// UPI payment class
class UpiPayment : public Payment {
public:
    // Display UPI payment details
    void pay(double amount) const override {
        cout << "Paid Rs. " << amount << " using UPI\n";
    }
};

// Net banking payment class
class NetBankingPayment : public Payment {
public:
    // Display net banking payment details
    void pay(double amount) const override {
        cout << "Paid Rs. " << amount << " using net banking\n";
    }
};

// Digital wallet payment class
class WalletPayment : public Payment {
public:
    // Display wallet payment details
    void pay(double amount) const override {
        cout << "Paid Rs. " << amount << " using digital wallet\n";
    }
};

// Function to process payment using any payment method
void processPayment(const Payment& payment, double amount) {
    payment.pay(amount);
}

int main() {
    // Create objects for different payment methods
    CardPayment card;
    UpiPayment upi;
    NetBankingPayment netBanking;
    WalletPayment wallet;

    // Process payments using the same function
    processPayment(card, 1250.0);
    processPayment(upi, 750.0);
    processPayment(netBanking, 500.0);
    processPayment(wallet, 300.0);

    return 0;
}