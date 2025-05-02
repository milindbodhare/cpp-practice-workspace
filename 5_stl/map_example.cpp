#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> age_map;
    age_map["Alice"] = 25;
    age_map["Bob"] = 30;

    for (const auto& pair : age_map) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }
    return 0;
}
