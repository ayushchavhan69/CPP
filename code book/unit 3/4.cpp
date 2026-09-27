#include <iostream>  // For input and output

// Class to store counter value
class Counter
{
private:
    int value;  // Stores counter value

public:
    // Constructor to set initial value
    explicit Counter(int initialValue = 0) : value(initialValue) {}

    // Overload prefix increment (++counter)
    Counter& operator++()
    {
        ++value;
        return *this;
    }

    // Overload postfix increment (counter++)
    Counter operator++(int)
    {
        Counter old = *this;  // Store old value
        ++value;
        return old;
    }

    // Overload prefix decrement (--counter)
    Counter& operator--()
    {
        --value;
        return *this;
    }

    // Overload postfix decrement (counter--)
    Counter operator--(int)
    {
        Counter old = *this;  // Store old value
        --value;
        return old;
    }

    // Display counter value
    void display() const
    {
        std::cout << value << '\n';
    }
};

int main()
{
    // Create counter object with initial value 5
    Counter counter(5);

    // Prefix increment
    std::cout << "After prefix increment: ";
    ++counter;
    counter.display();

    // Postfix increment
    std::cout << "Value returned by postfix increment: ";
    Counter oldInc = counter++;
    oldInc.display();

    std::cout << "Counter after postfix increment: ";
    counter.display();

    // Prefix decrement
    std::cout << "\nAfter prefix decrement: ";
    --counter;
    counter.display();

    // Postfix decrement
    std::cout << "Value returned by postfix decrement: ";
    Counter oldDec = counter--;
    oldDec.display();

    std::cout << "Counter after postfix decrement: ";
    counter.display();

    return 0;
}