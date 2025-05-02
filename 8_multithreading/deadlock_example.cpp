/*
- Two threads trying to acquire two locks in different orders can cause a deadlock.
*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1, m2;

void thread1() {
    std::lock_guard<std::mutex> lock1(m1);//At 1st CPU cycle thread1 will lock m1
    // and then it will try to lock m2 at 2nd CPU cycle, but it will be blocked
    // because thread2 has already locked m2
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::lock_guard<std::mutex> lock2(m2);
    std::cout << "Thread 1 done\n";
}

void thread2() {
    std::lock_guard<std::mutex> lock2(m2); //At 1st CPU cycle thread2 will lock m2
    // and then it will try to lock m1 at 2nd CPU cycle, but it will be blocked
    // because thread1 has already locked m1
    // So both threads are waiting for each other to release the locks
    // This is a deadlock situation
    // and will cause the program to hang
    // and will never be able to complete
    // and will never be able to release the locks
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::lock_guard<std::mutex> lock1(m1);
    std::cout << "Thread 2 done\n";
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
