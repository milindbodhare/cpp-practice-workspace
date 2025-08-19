#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int counter = 1;
int n = 20;

void print_odd() {
    while (counter <= n) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return counter % 2 != 0; });
        if (counter <= n) {
            std::cout << "Odd: " << counter << std::endl;
            counter++;
        }
        lock.unlock();
        cv.notify_one();
    }
}

void print_even() {
    while (counter <= n) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return counter % 2 == 0; });
        if (counter <= n) {
            std::cout << "Even: " << counter << std::endl;
            counter++;
        }
        lock.unlock();
        cv.notify_one();
    }
}

int main() {
    std::thread t1(print_odd);
    std::thread t2(print_even);

    t1.join();
    t2.join();

    return 0;
}