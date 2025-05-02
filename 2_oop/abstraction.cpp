#include <iostream>

class AbstractClass {
public:
    virtual void display() = 0; // Pure virtual function
};

class ConcreteClass : public AbstractClass {
public:
    void display() override {
        std::cout << "This is an implementation of the pure virtual function!" << std::endl;
    }
};

int main() {
    ConcreteClass obj;
    obj.display();
    return 0;
}
