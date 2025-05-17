#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

bool isEven(int num) {
    return num % 2 == 0;
}
bool isOdd(int num) {
    return num % 2 != 0;
}


int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    std::mutex mtx;

    auto evenThread = [&]() {
        for (int num : numbers) {
            if (isEven(num)) {
                std::lock_guard<std::mutex> lock(mtx);
                std::cout << num << " is even\n";
            }
        }
    };

    auto oddThread = [&]() {
        for (int num : numbers) {
            if (isOdd(num)) {
                std::lock_guard<std::mutex> lock(mtx);
                std::cout << num << " is odd\n";
            }
        }
    };

    std::thread t1(evenThread);
    std::thread t2(oddThread);

    t1.join();
    t2.join();

    return 0;

}