#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 2, 3, 4, 5};
    for (int num : s) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
