/*
- A critical section is a part of a program where shared resources like memory or files are 
accessed by multiple processes or threads. 
- To avoid issues like data inconsistency or race conditions, synchronization techniques ensure 
that only one process or thread uses the critical section at a time.
- When two or more threads tries to modify the same variable (common resource) at the same time, it is called Race
Condition.
- When race condition is not handled properly, it can lead to data inconsistency and unpredictable behavior (deadlocks).
- To avoid this, we can use mutexes (mutual exclusion locks) to ensure that only one thread can access the critical section at a time.
*/
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increment(int times) {
    for (int i = 0; i < times; ++i) {
        //++counter; // Not thread-safe!
        std::lock_guard<std::mutex> lock(mtx); 
        // Lock the mutex and lock_guard will unlock it automatically when it goes out of scope
        ++counter; // Increment the counter
    }
}

int main() {
    std::thread t1(increment, 100000);
    std::thread t2(increment, 100000);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}
