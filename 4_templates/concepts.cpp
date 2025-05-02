#include <iostream>
#include <concepts>

template <typename T>
concept Integer = std::integral<T>;

template <Integer T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4) << std::endl;  // Works for integers
    // std::cout << add(3.5, 4.5) << std::endl; // Compile-time error for non-integer types
    return 0;
}
