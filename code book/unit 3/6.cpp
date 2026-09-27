#include <iostream>  // For input and output

// Class to store distance
class Distance
{
private:
    int meters;  // Stores distance in meters

public:
    // Constructor to set distance
    explicit Distance(int value) : meters(value) {}

    // Overload greater than (>) operator
    bool operator>(const Distance& other) const
    {
        return meters > other.meters;
    }

    // Overload equal to (==) operator
    bool operator==(const Distance& other) const
    {
        return meters == other.meters;
    }

    // Display distance
    void display() const
    {
        std::cout << meters << " meters\n";
    }
};

int main()
{
    // Create distance objects
    Distance first(120);
    Distance second(90);
    Distance third(120);

    // Compare first and second distances
    if (first > second)
    {
        std::cout << "First distance is greater than second\n";
    }

    // Compare first and third distances
    if (first == third)
    {
        std::cout << "First distance and third distance are equal\n";
    }
    else
    {
        std::cout << "First distance and third distance are not equal\n";
    }

    return 0;
}