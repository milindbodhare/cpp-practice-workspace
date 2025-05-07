#include <iostream>
#include <string>
#include <utility>

// Step 1: User-defined types
class Person {
public:
    std::string name;
    int age;

    void display() const{
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Book {
public:
    std::string title;
    int pages;

    void display() const{
        std::cout << "Title: " << title << ", Pages: " << pages << std::endl;
    }
};

// Step 2: Variadic template function to print all arguments
void displayAll(){
    std::cout << "End of arguments" << std::endl;
}

template<typename T, typename... Args>
void displayAll(T first, Args... args){
    first.display();    // Call the display method of the first argument
    displayAll(args...); // Recursive call with the rest of the arguments
}

// Step 3: Variadic class template
// Step 3: Variadic class template
template<typename... Args>
class Container;

template<typename T, typename... Rest>
class Container<T, Rest...> {
    T head;
    Container<Rest...> tail;

public:
    Container(T h, Rest... r) : head(std::move(h)), tail(std::move(r)...) {}

    void print() const {
        head.print();
        tail.print();
    }
};

// Base case specialization
template<>
class Container<> {
public:
    void print() const {
        std::cout << "Container is empty.\n";
    }
};


int main(){
    Person p1{"Alice", 30};
    Person p2{"Bob", 25};
    Book b1{"C++ Primer", 980};

    std::cout << "=== Variadic Function ===\n";
    displayAll(p1, b1, p2); // Works on any number and order of user-defined types

    std::cout << "\n=== Variadic Class Template ===\n";
    Container<Person, Book, Person> c(p1, b1, p2);
    c.print();
}
