#include <iostream>
#include <memory>

using namespace std;

class Owner; //forward declaration

class Car{
public:
    std::shared_ptr<Owner> spOwner;
    Car() {
        cout << "Car created" << endl;
    }
    ~Car() {
        cout << "Car destroyed" << endl;
    }
};

class Owner{
public:
    std::weak_ptr<Car> spCar;
    Owner() {
        cout << "Owner created" << endl;
    }
    ~Owner() {
        cout << "Owner destroyed" << endl;
    }
};

int main() {
    std::shared_ptr<Car> car = std::make_shared<Car>();
    std::shared_ptr<Owner> owner = std::make_shared<Owner>();
    //std::shared_ptr<Car> car2(new Car()); //another way to create shared_ptr

    car->spOwner = owner;
    owner->spCar = car;

    cout << "Car and Owner created with cyclic reference." << endl;

    // Break the cycle using reset
    // This will decrement the reference count of both car and owner to 0
    // and delete the objects they point to.
    // Note: This is not the best way to break cyclic references.   
   
    //car->owner.reset(); 
    //owner->car.reset();

    cout << "Reference count of car: " << car.use_count() << endl;
    cout << "Reference count of owner: " << owner.use_count() << endl;
    //Cyclic reference not broken, even if the main goes out of scope pointers have reference count of 1 at least
    // In real-world applications, consider using weak_ptr to avoid this issue.

    //using weak ptrs safely
    if(std::shared_ptr<Car> carPtr = owner->spCar.lock()) {
        //safe to use car object
        cout << "Car is still alive." << endl;
    } else {
        cout << "Car is no longer alive." << endl;
    }


    //cout << "Cyclic reference broken." << endl;

    return 0;
}