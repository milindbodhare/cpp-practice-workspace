#include <iostream>
using namespace std;

// Base class
class Animal {
    public:
        //function overriding
        virtual void sound() { // Virtual function
            cout << "Animal makes a sound" << endl;
        }

        //function overloading
        void sound(int times) {
            for (int i = 0; i < times; i++) {
                cout << "Animal makes a sound" << endl;
            }
        }
};

// Derived class
class Dog : public Animal {
    public:
        void sound() override { // Override base class method
            cout << "Dog barks" << endl;
        }
};