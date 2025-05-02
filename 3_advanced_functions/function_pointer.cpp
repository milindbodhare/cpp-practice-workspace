#include <iostream>

void hello() {
    std::cout << "Hello, Function Pointer!" << std::endl;
}

int main() {
    void (*func_ptr)() = hello;
    func_ptr();
    return 0;
}
