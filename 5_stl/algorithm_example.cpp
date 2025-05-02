#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 3, 8, 1};
    std::sort(v.begin(), v.end());
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
