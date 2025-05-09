#include <iostream>  // Library for input and output
#include <string>    // Library to use string data type
using namespace std; // Using the standard namespace to avoid writing std:: each time

// Base class Animal
class Animal {
    protected:
        string name;  // Protected: allows access in derived classes (Cat, Dog, BigDog)
                      // If this were private, derived classes would NOT be able to access it directly

    public:
        // Constructor: initializes an Animal object with a name
        Animal(string name) 
        {
            this->name = name;  // Assign the passed name to the object's property
        }
    
        // Pure virtual function: must be overridden in derived classes
        virtual void greets() = 0;  // Interface only, no implementation
};

// Cat class inherits from Animal
class Cat : public Animal {
    // I had: private string name;
    // This is redundant because `Animal` already has a name field.
    // Also, private variables are not inherited, so redefining it hides the original one.
    
    public:
        // Constructor: calls Animal constructor to initialize the name
        // No need to assigns the name (redundant since Animal already has it)
        Cat(string name) : Animal(name) {}  
    
        // Override: implementing the pure virtual function from Animal
        void greets() override {
            cout << "Meow" << endl;  // Cat sound
        }
};

// Dog class inherits from Animal
class Dog : public Animal {
    // I had: private string name;
    // This is redundant because `Animal` already has a name field.
    // Also, private variables are not inherited, so redefining it hides the original one.
    
    public:
        // Constructor: initializes name via Animal's constructor
        // No need to assigns the name (redundant since Animal already has it)
        Dog(string name) : Animal(name) {}
    
        // Override: implementing Animal's greets method
        void greets() override {
            cout << "Woof" << endl;  // Dog sound
        }
    
        // Overloaded method: same name, but takes another Dog object as a parameter
        void greets(Dog another) {
            cout << "Woooof" << endl;  // Sound when greeting another dog
        }
};

// BigDog class inherits from Dog (multi-level inheritance)
class BigDog : public Dog {
    // I had: private string name;
    // This is redundant because `Animal` already has a name field.
    // Also, private variables are not inherited, so redefining it hides the original one.
    
    public:
        // Constructor: calls Dog constructor
        // No need to assigns the name (redundant since Animal already has it)
        BigDog(string name) : Dog(name) {}
    
        // Override: custom greeting for BigDog
        void greets() override {
            cout << "Wooow" << endl;  // Default BigDog sound
        }
    
        // Overloaded method: greeting another Dog
        void greets(Dog another) {
            cout << "Woooooow" << endl;  // Greeting for a normal Dog
        }
    
        // Overloaded method: greeting another BigDog
        void greets(BigDog another) {
            cout << "Wooooooooow" << endl;  // Greeting for another BigDog
        }
};

int main() {
    // Cat
    Cat cat("Kitty");
    cat.greets();  // Output: Meow

    // Dog
    Dog dog1("Rex");
    dog1.greets();  // Output: Woof

    Dog dog2("Buddy");
    dog1.greets(dog2);  // Output: Woooof

    // BigDog
    BigDog bigdog1("Max");
    bigdog1.greets();  // Output: Wooow

    Dog dog3("Charlie");
    bigdog1.greets(dog3);  // Output: Woooooow

    BigDog bigdog2("Rocky");
    bigdog1.greets(bigdog2);  // Output: Wooooooooow
    
    /* another way To create objects using pointers. you can use Animal* pointers and allocate the derived class objects using new. This way, you can call overridden methods like greets() via dynamic dispatch.

    // Cat
    Animal* cat = new Cat("Kitty");
    cat->greets();  // Output: Meow

    // Dog
    Dog* dog1 = new Dog("Rex");
    dog1->greets();  // Output: Woof

    Dog* dog2 = new Dog("Buddy");
    dog1->greets(*dog2);  // Output: Woooof

    // BigDog
    BigDog* bigdog1 = new BigDog("Max");
    bigdog1->greets();  // Output: Wooow

    Dog* dog3 = new Dog("Charlie");
    bigdog1->greets(*dog3);  // Output: Woooooow

    BigDog* bigdog2 = new BigDog("Rocky");
    bigdog1->greets(*bigdog2);  // Output: Wooooooooow

    // Cleanup (good practice to avoid memory leaks)
    delete cat;
    delete dog1;
    delete dog2;
    delete dog3;
    delete bigdog1;
    delete bigdog2;
    */

    return 0;  // End of program
}
