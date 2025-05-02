#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>

std::mutex coutMutex;

class ThreadPool {
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> taskQueue;

    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;

public:
    explicit ThreadPool(size_t threads = std::thread::hardware_concurrency()) : stop(false) {
        for (size_t i = 0; i < threads; ++i) {
            workers.emplace_back([this]() {
                while (true) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queueMutex);
                        this->condition.wait(lock, [this]() {
                            return this->stop || !this->taskQueue.empty();
                        });

                        if (this->stop && this->taskQueue.empty()) return;
                        task = std::move(this->taskQueue.front());
                        this->taskQueue.pop();
                    }

                    task(); // execute the task
                }
            });
        }
    }

    // Submit a task to the thread pool
    void enqueue(std::function<void()> task) {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            taskQueue.emplace(std::move(task));
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        stop = true;
        condition.notify_all();
        for (std::thread &worker : workers) {
            if (worker.joinable()) worker.join();
        }
    }
};

int main() {
    ThreadPool pool(4); // create pool with 4 threads

    for (int i = 0; i < 10; ++i) {
        pool.enqueue([i]() {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "Thread pool task " << i << " executed in thread ID: " << std::this_thread::get_id() << "\n";
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(2)); // give time for all tasks to complete
    return 0;
}
