#include <iostream>
#include <cstdarg>

void print_numbers(int num, ...) {
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; ++i) {
        std::cout << va_arg(args, int) << " ";
    }
    va_end(args);
    std::cout << std::endl;
}

int main() {
    print_numbers(3, 1, 2, 3);
    return 0;
}
