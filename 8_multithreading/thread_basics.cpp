/*
Multithreading and multiprocessing are both techniques for achieving concurrency in C++, but 
they differ in how they utilize system resources.

- Multiprocessing involves creating multiple independent processes, each with its own memory 
space and resources.
- Multithreading involves creating multiple threads within a single process. These threads share 
the same memory space and resources of the parent process.

## 🔧 Optimal Use Cases

| Use Case                                  | Best Approach          | Why                                              |
|-------------------------------------------|------------------------|--------------------------------------------------|
| Tasks with shared data or memory          | Threads                | Share memory easily, low overhead               |
| Completely independent tasks              | Processes or Threads   | Either works; processes if isolation is important |
| IO-bound tasks (e.g., waiting on disk/network) | Many threads        | Threads can sleep while waiting                 |
| CPU-bound tasks (e.g., calculations)      | Threads = CPU cores    | Too many threads cause context switching overhead |

*/
#include <iostream>
#include <thread>
#include <mutex>

std::mutex coutMutex;

void task(int id) {
    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout << "Task " << id << " is running in thread ID: " << std::this_thread::get_id() << "\n";
}

int main() {
    std::cout << "Main thread ID: " << std::this_thread::get_id() << "\n";

    // 1. Thread creation
    std::thread t1(task, 1);
    std::thread t2(task, 2);

    // 2. Check if joinable
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();

    // 3. Detach thread (runs independently)
    std::thread t3([] {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Detached thread running ID: " << std::this_thread::get_id() << "\n";
    });
    t3.detach();

    // 4. Get hardware concurrency
    std::cout << "Hardware concurrency: " << std::thread::hardware_concurrency() << "\n";

    std::this_thread::sleep_for(std::chrono::seconds(1)); // wait for detached thread
    return 0;
}
