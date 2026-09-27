#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function to display animal sound
    virtual void sound() const {
        cout << "Animal makes a sound\n";
    }

    // Virtual destructor
    virtual ~Animal() = default;
};

// Dog class inherits from Animal
class Dog : public Animal {
public:
    // Overrides the sound() function
    void sound() const override {
        cout << "Dog barks\n";
    }
};

// Cat class inherits from Animal
class Cat : public Animal {
public:
    // Overrides the sound() function
    void sound() const override {
        cout << "Cat meows\n";
    }
};

// Cow class inherits from Animal
class Cow : public Animal {
public:
    // Overrides the sound() function
    void sound() const override {
        cout << "Cow moos\n";
    }
};

int main() {
    // Create objects of different animals
    Dog dog;
    Cat cat;
    Cow cow;

    // Base class pointer points to Dog object
    Animal* animal = &dog;
    animal->sound();

    // Same pointer now points to Cat object
    animal = &cat;
    animal->sound();

    // Same pointer now points to Cow object
    animal = &cow;
    animal->sound();

    return 0;
}