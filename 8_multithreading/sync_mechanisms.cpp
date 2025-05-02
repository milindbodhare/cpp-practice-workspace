/*
# C++ Synchronization Mechanisms
| Mechanism                 | Use Case                      | Thread Safe | Waits | Lock-Free |
| ------------------------- | ----------------------------- | ----------- | ----- | --------- |
| `std::mutex`              | Simple exclusive lock         | ✅           | ✅     | ❌         |
| `std::recursive_mutex`    | Recursion with same thread    | ✅           | ✅     | ❌         |
| `std::timed_mutex`        | Time-based lock attempts      | ✅           | ✅     | ❌         |
| `std::shared_mutex`       | Reader/writer scenarios       | ✅           | ✅     | ❌         |
| `std::condition_variable` | Signaling between threads     | ✅           | ✅     | ❌         |
| `std::lock_guard`         | Basic RAII mutex lock         | ✅           | ✅     | ❌         |
| `std::unique_lock`        | Flexible RAII locking         | ✅           | ✅     | ❌         |
| `std::scoped_lock`        | Locks multiple mutexes safely | ✅           | ✅     | ❌         |
| `std::atomic`             | Lock-free counter/sync        | ✅           | ❌     | ✅         |

*/

#include <iostream>
#include <mutex>
#include <chrono>
#include <shared_mutex>
#include <condition_variable>
#include <atomic>

//recursive_mutex: Allows the same thread to lock multiple times (used in recursion).
std::recursive_mutex rmtx;
void recursiveFunc(int depth) {
    rmtx.lock();
    if (depth > 0) recursiveFunc(depth - 1);
    rmtx.unlock();
}

//timed_mutex: Supports time-limited lock attempts.
std::timed_mutex tmtx;
void tryLockFunc() {
    if (tmtx.try_lock_for(std::chrono::milliseconds(100))) {
        // Critical section
        tmtx.unlock();
    } else {
        // Timeout: Couldn't lock
    }
}


//shared_mutex: Allows multiple readers or one writer.
std::shared_mutex shmtx;
void reader() {
    std::shared_lock lock(shmtx); // multiple readers allowed
}

void writer() {
    std::unique_lock lock(shmtx); // exclusive write access
}

//lock_guard: RAII wrapper for std::mutex. Locks on creation, unlocks on destruction.
std::mutex m;
void func() {
    std::lock_guard<std::mutex> lock(m); // Auto unlock
}

//unique_lock: Flexible RAII lock – supports manual lock/unlock, moveable, and deferred locking.
std::mutex m;
void func() {
    std::unique_lock<std::mutex> lock(m, std::defer_lock);
    // Do something
    lock.lock();
    // Critical section
    lock.unlock();
}

//scoped_lock: Locks multiple mutexes together (avoids deadlocks).
std::mutex m1, m2;
void func() {
    std::scoped_lock lock(m1, m2); // Locks both safely
}

//condition_variable: Used to block a thread until a condition is met.
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    // Proceed when ready
}

void producer() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
}


//atomic: Provides lock-free operations on simple data types.
std::atomic<int> counter = 0;

void increment() {
    counter.fetch_add(1, std::memory_order_relaxed);
}
