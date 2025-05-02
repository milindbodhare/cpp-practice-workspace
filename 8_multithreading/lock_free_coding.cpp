/*
Q. What is Lock-Free Coding?
- Lock-free programming is a concurrency design technique where multiple threads can operate on 
shared data without using mutual exclusion locks like std::mutex. The goal is to prevent 
blocking, reduce contention, and ensure high performance—especially in real-time or low-latency 
systems.

Q. How Is Lock-Free Achieved?
    1. Using atomic operations from <atomic>, especially:
        - std::atomic
        - compare_exchange_weak / strong
        - fetch_add, fetch_sub, etc.
    2. Avoiding OS-level blocking primitives like mutex, condition_variable.
    3. Carefully structuring the algorithm to be non-blocking, yet thread-safe.

🧠 Rule of Thumb
"Use lock-free only when profiling proves locks are the bottleneck, and you're confident 
in concurrent memory models."

# 📊 Lock-Based vs Lock-Free Queue Comparison

| Feature                     | Lock-Based Queue                                  | Lock-Free Queue                                       |
|----------------------------|---------------------------------------------------|-------------------------------------------------------|
| **Synchronization**        | Uses `std::mutex` or similar locking mechanism    | Uses atomic operations (`std::atomic`, CAS, etc.)     |
| **Thread Blocking**        | Yes – threads may block and wait                  | No blocking – threads never wait                      |
| **Performance (Low Contention)** | Very good – minimal lock overhead              | Excellent – atomic operations are fast                |
| **Performance (High Contention)** | Degrades – lock convoy, cache-line ping-pong  | Scales better – avoids blocking, higher throughput    |
| **Fairness**               | Generally fair – FIFO via mutex                  | No fairness guarantees                                |
| **Ease of Implementation** | Simple and intuitive                              | Complex – requires careful handling of memory & logic |
| **Debugging**              | Easier – deterministic and scoped                 | Hard – non-deterministic bugs, memory ordering issues |
| **Memory Reclamation**     | Automatic via RAII                                | Hard – requires hazard pointers or epoch-based GC     |
| **Use Case Fit**           | General-purpose multithreading                   | High-performance, low-latency systems                 |
| **Example Libraries**      | `std::queue` + `std::mutex`, `std::condition_variable` | `moodycamel::ConcurrentQueue`, `folly::MPMCQueue` |
| **Risk of Deadlocks**      | Yes – if locks are not managed correctly          | No – by design (but can have livelock)                |

---

## 📝 Summary

- 🔐 **Lock-Based** queues are easier, safer, and often "fast enough" for typical software.
- ⚡ **Lock-Free** queues offer high-performance concurrency, but are complex and error-prone.
- ✅ Use **lock-free** when latency matters (e.g., trading, games, real-time systems).
- 🧩 Always benchmark before optimizing—clarity matters more than micro-optimization in many domains.


Problem Statement:
Implement a thread-safe stack that allows multiple producers and consumers to push and pop 
items without using locks.
*/

#include <atomic>
#include <thread>
#include <iostream>
#include <vector>
#include <optional>

// Node structure
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& val) : data(val), next(nullptr) {}
};

// Lock-free stack class
template<typename T>
class LockFreeStack {
    std::atomic<Node<T>*> head;

public:
    LockFreeStack() : head(nullptr) {}

    void push(const T& value) {
        Node<T>* new_node = new Node<T>(value);
        new_node->next = head.load(std::memory_order_relaxed);

        // CAS loop: keep trying to insert
        while (!head.compare_exchange_weak(
            new_node->next, new_node,
            std::memory_order_release,
            std::memory_order_relaxed)) {}
    }

    std::optional<T> pop() {
        Node<T>* old_head = head.load(std::memory_order_relaxed);
        while (old_head &&
               !head.compare_exchange_weak(
                   old_head, old_head->next,
                   std::memory_order_acquire,
                   std::memory_order_relaxed)) {}

        if (old_head) {
            T value = old_head->data;
            delete old_head;
            return value;
        }
        return std::nullopt;
    }

    ~LockFreeStack() {
        while (pop()) {} // Clean up
    }
};

void producer(LockFreeStack<int>& stack, int start) {
    for (int i = start; i < start + 5; ++i) {
        stack.push(i);
        std::cout << "Pushed: " << i << "\n";
    }
}

void consumer(LockFreeStack<int>& stack) {
    for (int i = 0; i < 5; ++i) {
        auto val = stack.pop();
        if (val) {
            std::cout << "Popped: " << *val << "\n";
        }
    }
}

int main() {
    LockFreeStack<int> stack;

    std::thread t1(producer, std::ref(stack), 100);
    std::thread t2(producer, std::ref(stack), 200);
    std::thread t3(consumer, std::ref(stack));
    std::thread t4(consumer, std::ref(stack));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
