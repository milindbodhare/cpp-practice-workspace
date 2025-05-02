#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

class EventLogger {
private:
    std::ofstream logFile;
    std::mutex mtx;

    // Convert LogLevel enum to string
    std::string levelToString(LogLevel level) const {
        switch (level) {
            case LogLevel::INFO: return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }

    // Get current timestamp
    std::string getCurrentTimestamp() const {
        auto now = std::chrono::system_clock::now();
        std::time_t tNow = std::chrono::system_clock::to_time_t(now);
        std::tm localTime = *std::localtime(&tNow);

        std::ostringstream oss;
        oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

public:
    // Constructor: Open file
    EventLogger(const std::string& filename) {
        logFile.open(filename, std::ios::app);  // append mode
        if (logFile.is_open()) {
            logFile << "=== Log Started at " << getCurrentTimestamp() << " ===\n";
        } else {
            std::cerr << "ERROR: Could not open log file!\n";
        }
    }

    // Thread-safe log function
    void log(LogLevel level, const std::string& message) {
        std::lock_guard<std::mutex> lock(mtx);
        if (logFile.is_open()) {
            logFile << "[" << getCurrentTimestamp() << "] "
                    << "[" << levelToString(level) << "] "
                    << message << '\n';
        }
    }

    // Destructor: Close file
    ~EventLogger() {
        std::lock_guard<std::mutex> lock(mtx);
        if (logFile.is_open()) {
            logFile << "=== Log Ended at " << getCurrentTimestamp() << " ===\n";
            logFile.close();
        }
    }
};

void worker(EventLogger& logger, int id) {
    for (int i = 0; i < 5; ++i) {
        logger.log(LogLevel::INFO, "Thread " + std::to_string(id) + " - iteration " + std::to_string(i));
    }
}

int main() {
    EventLogger logger("event.log");

    std::thread t1(worker, std::ref(logger), 1);
    std::thread t2(worker, std::ref(logger), 2);

    t1.join();
    t2.join();

    logger.log(LogLevel::WARNING, "This is a warning message.");
    logger.log(LogLevel::ERROR, "This is an error message.");

    std::cout << "Logging complete.\n";
    return 0;
}
