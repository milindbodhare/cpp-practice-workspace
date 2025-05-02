#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
