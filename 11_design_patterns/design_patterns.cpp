/*
- Design Patterns in C++, grouped into Creational, Structural, and Behavioral categories.
- Each pattern is briefly described with a use case example:
+-------------------+--------------+---------------------------------------------+
| Pattern           | Category     | Use Case Example                            |
+-------------------+--------------+---------------------------------------------+
| Singleton         | Creational   | Config Manager                              |
| Factory           | Creational   | Shape Object Generator                      |
| Abstract Factory  | Creational   | Cross-platform UI Toolkit                   |
| Builder           | Creational   | Car Configurator                            |
| Prototype         | Creational   | Object Cloning                              |
| Adapter           | Structural   | Legacy System Compatibility                 |
| Bridge            | Structural   | Device Control with Abstraction             |
| Composite         | Structural   | Tree Structures (e.g., File System)         |
| Decorator         | Structural   | Add Features (e.g., Milk in Coffee)         |
| Facade            | Structural   | Simplify Complex Subsystems (e.g., Computer)|
| Observer          | Behavioral   | GUI Event Notification                      |
| Strategy          | Behavioral   | Sorting Algorithm Switch                    |
| Command           | Behavioral   | Remote Control System                       |
| State             | Behavioral   | Traffic Light / Vending Machine             |
| Iterator          | Behavioral   | Collection Traversal                        |
+-------------------+--------------+---------------------------------------------+

*/

#include <iostream>
#include <string>
#include <vector>

// 1. Singleton Pattern
class Singleton {
private:
    static Singleton* instance;
    Singleton() { std::cout << "Singleton created\n"; }
public:
    static Singleton* getInstance() {
        if (!instance) instance = new Singleton();
        return instance;
    }
    void greet() { std::cout << "Hello from Singleton\n"; }
 };
Singleton* Singleton::instance = nullptr;

// 2. Factory Pattern
class Shape {
public: 
    virtual void draw() = 0; 
};
class Circle : public Shape {
    void draw() override { std::cout << "Drawing Circle\n"; }
    
};
class Square : public Shape {
    void draw() override { std::cout << "Drawing Square\n"; }
};
class ShapeFactory {
public:
    static Shape* create(const std::string& type) {
        if (type == "circle") return new Circle();
        else if (type == "square") return new Square();
        return nullptr;
    }
};

// 3. Abstract Factory Pattern
class Button {
    public: 
    virtual void render() = 0; 
};
class WinButton : public Button {
    void render() override { std::cout << "Windows Button\n"; }
};
class MacButton : public Button {
    void render() override { std::cout << "Mac Button\n"; }
};
class GUIFactory {
    public: 
    virtual Button* createButton() = 0; 
};
class WinFactory : public GUIFactory {
    Button* createButton() override { return new WinButton(); }
};
class MacFactory : public GUIFactory {
    Button* createButton() override { return new MacButton(); }
};
    
// 4. Builder Pattern
class Car {
public:
    std::string engine, wheels;
    void show() { std::cout << "Engine: " << engine << ", Wheels: " << wheels << "\n"; }
};
class CarBuilder {
    Car car;
public:
    CarBuilder& setEngine(const std::string& e) { car.engine = e; return *this; }
    CarBuilder& setWheels(const std::string& w) { car.wheels = w; return *this; }
    Car build() { return car; }
};
// 5. Prototype Pattern
class Prototype {
public: 
    virtual Prototype* clone() = 0; virtual void print() = 0; 
};
class Concrete : public Prototype {
    int value;
public:
    Concrete(int v) : value(v) {}
    Prototype* clone() override { return new Concrete(*this); }
    void print() override { std::cout << "Value: " << value << "\n"; }
};

// 6. Adapter Pattern
class OldPrinter {
public: 
    void printOld() { std::cout << "Old Printer\n"; } 
};
class NewPrinter {
public: 
    virtual void print() = 0; 
};
class Adapter : public NewPrinter {
    OldPrinter* oldPrinter;
public:
    Adapter(OldPrinter* op) : oldPrinter(op) {}
    void print() override { oldPrinter->printOld(); }
};

// 7. Bridge Pattern
class Device {
public: 
    virtual void on() = 0; 
};
class TV : public Device {
    void on() override { std::cout << "TV On\n"; }
};
class Remote {
protected:
    Device* device;
public:
    Remote(Device* d) : device(d) {}
    virtual void pressPower() { device->on(); }
};

// 8. Composite Pattern
class Component {
public: 
    virtual void show() = 0; 
};
class Leaf : public Component {
    void show() override { std::cout << "Leaf\n"; }
};
class Composite : public Component {
        std::vector<Component*> children;
public:
    void add(Component* c) { children.push_back(c); }
    void show() override {
        for (auto c : children) c->show();
    }
};

// 9. Decorator Pattern
class Coffee {
public: 
    virtual int cost() = 0; 
};
class Basic : public Coffee {
    int cost() override { return 5; }
};
class Milk : public Coffee {
    Coffee* base;
public:
    Milk(Coffee* b) : base(b) {}
    int cost() override { return base->cost() + 2; }
};

// 10. Facade Pattern
class CPU {
public: 
    void start() { std::cout << "CPU start\n"; } 
};
class Memory { 
public: 
    void load() { std::cout << "Memory load\n"; } 
};
class Computer {
    CPU cpu; 
    Memory mem;
public: 
    void start() { cpu.start(); mem.load(); }
};


// 11. Observer Pattern
class Observer {
public: 
    virtual void update(int val) = 0; 
};
class Subject {
    std::vector<Observer*> observers;
    int data;
public:
    void attach(Observer* o) { observers.push_back(o); }
    void setData(int d) {
        data = d;
        for (auto o : observers) o->update(d);
    }
};
class ConcreteObserver : public Observer {
public: 
    void update(int val) override { std::cout << "Notified: " << val << "\n"; }
};


// 12. Strategy Pattern
class Strategy {
public: 
    virtual void execute() = 0; 
};
class QuickSort : public Strategy {
    void execute() override { std::cout << "QuickSort\n"; }
};
class MergeSort : public Strategy {
    void execute() override { std::cout << "MergeSort\n"; }
};
class Context {
    Strategy* strategy;
public:
    void set(Strategy* s) { strategy = s; }
    void sort() { strategy->execute(); }
};

// 13. Command Pattern
class Command {
public: 
    virtual void execute() = 0; 
};
class Light {
public: 
    void on() { std::cout << "Light On\n"; }
};
class LightOnCommand : public Command {
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() override { light->on(); }
};

// 14. State Pattern
class State {
public: 
    virtual void handle() = 0; 
};
class On : public State {
    void handle() override { std::cout << "State: ON\n"; }
};
class Off : public State {
    void handle() override { std::cout << "State: OFF\n"; }
};
class Contextst {
    State* state;
public:
    void set(State* s) { state = s; }
    void request() { state->handle(); }
};
    
    

int main()
{
    // Singleton usage
    Singleton::getInstance()->greet();
    // Factory usage
    Shape* s = ShapeFactory::create("circle");
    s->draw();
    delete s;
    // Abstract Factory usage
    GUIFactory* factory = new WinFactory();
    Button* btn = factory->createButton();
    btn->render();
    delete btn; 
    delete factory;
    // Builder usage
    Car car = CarBuilder().setEngine("V8").setWheels("Alloy").build();
    car.show();
    // Prototype usage
    Concrete original(42);
    Prototype* copy = original.clone();
    copy->print();
    delete copy;
    // Adapter usage
    OldPrinter op;
    NewPrinter* np = new Adapter(&op);
    np->print();
    delete np;
    // Bridge usage
    TV tv;
    Remote remote(&tv);
    remote.pressPower();
    // Composite usage
    Leaf l1, l2;
    Composite comp;
    comp.add(&l1); 
    comp.add(&l2);
    comp.show();
    // Decorator usage
    Coffee* coffee = new Milk(new Basic());
    std::cout << "Cost: " << coffee->cost() << "\n";
    delete coffee;
    // Facade usage
    Computer c;
    c.start();
    // Observer usage
    Subject sub;
    ConcreteObserver o1;
    sub.attach(&o1);
    sub.setData(100);

    // Strategy usage
    Context ctx;
    QuickSort q;
    ctx.set(&q);
    ctx.sort();

    // Command usage
    Light l;
    Command* cmd = new LightOnCommand(&l);
    cmd->execute();
    delete cmd;

    // State usage
    Contextst ctxx;
    On on; 
    Off off;
    ctxx.set(&on); 
    ctxx.request();
    ctxx.set(&off); 
    ctxx.request();

    return 0;
}
    