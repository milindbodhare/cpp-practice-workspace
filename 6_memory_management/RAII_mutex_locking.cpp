#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

class LockGuard {
public:
    LockGuard(std::mutex& m) : mutex_(m) {
        mutex_.lock();  // Lock acquired
        std::cout << "Lock acquired by thread.\n";
    }

    ~LockGuard() {
        mutex_.unlock();  // Lock released
        std::cout << "Lock released by thread.\n";
    }

private:
    std::mutex& mutex_;
};

void printMessage(const std::string& msg) {
    LockGuard lock(mtx);  // Lock is acquired on object creation
    std::cout << msg << std::endl;
    // Lock is released automatically at end of scope
}

int main() {
    std::thread t1(printMessage, "Hello from Thread 1");
    std::thread t2(printMessage, "Hello from Thread 2");

    t1.join();
    t2.join();

    return 0;
}
