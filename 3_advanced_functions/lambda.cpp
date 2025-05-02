#include <iostream>

int main() {
    auto sum = [](int a, int b) { return a + b; };
    std::cout << "Sum: " << sum(5, 7) << std::endl;
    return 0;
}
