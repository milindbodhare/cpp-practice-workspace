/*
Avoiding deadlocks can be achieved by following these strategies:
    1) Avoid deadlocks by ensuring that all threads acquire locks in the same order.
    e.g. 
        // Good order
        std::lock_guard<std::mutex> lockA(mutexA);
        std::lock_guard<std::mutex> lockB(mutexB);
    2) Use std::lock() or std::scoped_lock to lock multiple mutexes at once, preventing deadlocks.
    e.g.
        std::scoped_lock lock(mutexA, mutexB);  // Locks both atomically
    3) Use std::unique_lock with std::try_lock() to attempt to lock without blocking.
    e.g.
        std::unique_lock<std::mutex> lock(mutexA, std::try_to_lock);
        if (lock.owns_lock()) {
            // Do work
        }
    4) Use std::timed_mutex to set a timeout for acquiring locks.
    e.g.
        std::timed_mutex mtx;
        if (mtx.try_lock_for(std::chrono::seconds(1))) {
            // Do work
            mtx.unlock();
        } else {
            // Handle timeout
        }
    5) Use std::shared_mutex for shared read access and exclusive write access.
    e.g.
        std::shared_mutex sharedMtx;
        std::shared_lock<std::shared_mutex> readLock(sharedMtx); // for reading
        std::unique_lock<std::shared_mutex> writeLock(sharedMtx); // for writing
    6) Use std::condition_variable to notify threads when a resource is available.
    e.g.
        std::condition_variable cv;
        std::mutex mtx;
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return resource_available; });
        // Do work with the resource
    7) Use std::future and std::promise for thread-safe communication between threads.
    e.g.
        std::promise<int> promise;
        std::future<int> future = promise.get_future();
        std::thread t([&promise] {
            // Do work
            promise.set_value(result);
        });
        // Wait for the result
        int result = future.get();
        t.join();
    8) Use std::atomic for simple data types to avoid locks.
    e.g.
        std::atomic<int> atomicCounter;
        atomicCounter.fetch_add(1); // Increment atomically
*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1, m2;

void thread1() {
    std::lock(m1, m2);
    std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);
    std::cout << "Thread 1 done\n";
}

void thread2() {
    std::lock(m1, m2);
    std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);
    std::cout << "Thread 2 done\n";
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
