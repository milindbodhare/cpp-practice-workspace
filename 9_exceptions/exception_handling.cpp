#include <iostream>
#include <stdexcept>   // For standard exceptions
#include <string>

// 4. Custom Exception Class
class MyCustomException : public std::exception {
    std::string msg;
public:
    MyCustomException(const std::string& message) : msg(message) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

// Function to demonstrate standard exceptions
void divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero error");
    }
    std::cout << "Result: " << a / b << "\n";
}

// 7. noexcept Example
void safeFunction() noexcept {
    std::cout << "This function is marked noexcept and should not throw.\n";
}

// 6. Rethrow example
void rethrowExample() {
    try {
        throw std::logic_error("Initial logic error");
    } catch (...) {
        std::cout << "Caught and rethrowing...\n";
        throw;  // Rethrow the same exception
    }
}

int main() {
    // 1. Basic try-catch block
    try {
        std::cout << "\n1. Basic try-catch:\n";
        divide(10, 2);
    } catch (const std::exception& e) {
        std::cout << "Caught Exception: " << e.what() << "\n";
    }

    // 2. Multiple catch blocks
    try {
        std::cout << "\n2. Multiple catch blocks:\n";
        divide(10, 0);  // Will throw
    } catch (const std::logic_error& e) {
        std::cout << "Logic Error: " << e.what() << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Runtime Error: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Unknown exception caught!\n";
    }

    // 3. Generic catch block
    try {
        std::cout << "\n3. Generic catch:\n";
        throw 42;  // Throwing a primitive
    } catch (int x) {
        std::cout << "Caught int: " << x << "\n";
    } catch (...) {
        std::cout << "Caught an unknown exception\n";
    }

    // 4. Custom exception class
    try {
        std::cout << "\n4. Custom exception:\n";
        throw MyCustomException("Something custom went wrong!");
    } catch (const MyCustomException& e) {
        std::cout << "Caught MyCustomException: " << e.what() << "\n";
    }

    // 5. Standard exceptions
    try {
        std::cout << "\n5. Standard exceptions:\n";
        std::string s = "abc";
        std::cout << s.at(10);  // Will throw std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Out of Range Error: " << e.what() << "\n";
    }

    // 6. Rethrowing exception
    try {
        std::cout << "\n6. Rethrowing exceptions:\n";
        rethrowExample();
    } catch (const std::exception& e) {
        std::cout << "Rethrown exception caught in main: " << e.what() << "\n";
    }

    // 7. noexcept demonstration
    std::cout << "\n7. noexcept function:\n";
    safeFunction();

    // 8. Stack unwinding demonstration
    try {
        std::cout << "\n8. Stack unwinding:\n";
        struct DestructorCheck {
            ~DestructorCheck() {
                std::cout << "Destructor called during stack unwinding.\n";
            }
        } obj;
        throw std::runtime_error("Unwinding demo exception");
    } catch (const std::exception& e) {
        std::cout << "Caught during stack unwinding: " << e.what() << "\n";
    }

    // 9. Nested try-catch
    try {
        std::cout << "\n9. Nested try-catch:\n";
        try {
            throw std::runtime_error("Inner block exception");
        } catch (const std::runtime_error& e) {
            std::cout << "Caught inside inner block: " << e.what() << "\n";
            throw;  // Rethrow to outer block
        }
    } catch (...) {
        std::cout << "Caught in outer block after rethrow\n";
    }

    // 10. Throwing primitive type
    try {
        std::cout << "\n10. Throwing primitive type:\n";
        throw 'E';
    } catch (char c) {
        std::cout << "Caught char exception: " << c << "\n";
    }

    std::cout << "\nAll exceptions handled. Program completed.\n";
    return 0;
}
