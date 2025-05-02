#include <iostream>

template <typename T>
void display(T t) {
    std::cout << "Generic: " << t << std::endl;
}

template <>
void display<int>(int i) {
    std::cout << "Specialized for int: " << i << std::endl;
}

int main() {
    display(5);    // Will call specialized version for int
    display(3.14); // Will call generic version
    return 0;
}
