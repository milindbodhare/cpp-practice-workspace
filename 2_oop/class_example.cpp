#include <iostream>
using namespace std;

// Class declaration
class Car {
    public:
        string brand;
        string model;
        int year;

        // Constructor
        Car(string b, string m, int y) {
            brand = b;
            model = m;
            year = y;
        }

        // Method to display car details
        void display() {
            cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
        }
    };

int main() {
    // Creating an object of the Car class
    Car myCar("Toyota", "Corolla", 2020);
    // Calling the method to display car details
    myCar.display();

    // Creating pointer object using dynamic memory allocation
    Car* obj = new Car("Honda", "Civic", 2021);
    obj->display();

    return 0;
}