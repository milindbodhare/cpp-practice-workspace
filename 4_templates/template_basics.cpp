#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Int addition: " << add(3, 4) << std::endl;
    std::cout << "Double addition: " << add(3.5, 4.5) << std::endl;
    return 0;
}
