#include <iostream>

using namespace std;

// Base class
class Vehicle {
    public:
        string brand;
        int year;

        // Constructor
        Vehicle(string b, int y) {
            brand = b;
            year = y;
        }

        // Method to display vehicle details
        void display() {
            cout << "Brand: " << brand << ", Year: " << year << endl;
        }
};

// Derived class
class Car : public Vehicle {
    public:
        string model;

        // Constructor
        Car(string b, int y, string m) : Vehicle(b, y) {
            model = m;
        }

        // Method to display car details
        void display() {
            cout << "Brand: " << brand << ", Year: " << year << ", Model: " << model << endl;
        }
};

int main() {
    // Creating an object of the Vehicle class
    Vehicle myVehicle("Toyota", 2020);
    
    myVehicle.display();

    // Creating an object of the Car class
    Car myCar("Honda", 2021, "Civic");
    myCar.display();

    // Creating pointer object using dynamic memory allocation
    Vehicle* obj = new Car("Ford", 2022, "Mustang");
    obj->display();

    // Deleting dynamically allocated memory
    delete obj;

    return 0;
}