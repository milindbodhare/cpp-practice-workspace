/*
Problems with Normal Pointers
Memory Leaks: 
This occurs when memory is repeatedly allocated by a program but never freed. This leads to 
excessive memory consumption and eventually leads to a system crash. 
Wild Pointers: 
A pointer that never be initialize with valid object or address called wild pointer.
Dangling Pointers: 
Assume there is a pointer that refers to memory which was deallocated earlier in the program, 
that pointer is called a dangling pointer.
e.g.
int main() {
    
    // Infinite Loop
    while (1) {
        
        // Create a variable 
        // in heap memory using pointer
        int* ptr = new int; //memory is allocated but not freed (memory leak)
    }
    return 0;
}

SMART POINTERS

Smart pointer is wrapper class over a pointer that acts as a pointer but automatically manages 
the memory it points to. It ensures that memory is properly deallocated when no longer needed, 
preventing memory leaks. It is a part of <memory> header file.
Smart pointers are implemented as templates so we can create a smart pointer to any type of 
memory.

TYPES
C++ libraries provide implementations of smart pointers in the following types:
    1. auto_ptr :
    In C++, auto_ptr is a smart pointer that automatically manages the lifetime of a dynamically
    allocated object. It takes ownership of the object it points to, ensuring that the object 
    is automatically deleted when the auto_ptr goes out of scope.

    2. unique_ptr :
    unique_ptr stores one pointer only at a time. We cannot copy unique_ptr, only transfer 
    ownership of the object to another unique_ptr using the move() method.

    3. shared_ptr :
    By using shared_ptr, more than one pointer can point to same object at a time, and it will 
    maintain a reference counter using the use_count() method.

    4. weak_ptr :
    weak_ptr is a smart pointer that holds a non-owning reference to an object. It’s much more 
    similar to shared_ptr except it will not maintain a reference counter. In this case, a 
    pointer will not have a stronghold on the object. The reason is to avoid the circular 
    dependency created by two or more object pointing to each other using shared_ptr.

*/

#include <iostream>
#include <memory>
class Demo {
public:
    Demo() { std::cout << "Constructed" << std::endl; }
    ~Demo() { std::cout << "Destroyed" << std::endl; }
};
int main() {
    std::auto_ptr<Demo> p1(new Demo()); // auto_ptr is deprecated in C++11
    std::auto_ptr<Demo> p2 = p1; // Ownership is transferred to p2, p1 is now null

    std::unique_ptr<Demo> d1 = std::make_unique<Demo>(); // Automatically deallocates memory when it goes out of scope
    std::unique_ptr<Demo> d2 = std::move(d1); // Transfer ownership to d2

    std::shared_ptr<Demo> s1 = std::make_shared<Demo>(); // Reference count is 1
    std::shared_ptr<Demo> s2 = s1; // Reference count is now 2 
    // Both s1 and s2 point to the same object
    std::cout << "Reference count: " << s1.use_count() << std::endl; // Output: 2
}
