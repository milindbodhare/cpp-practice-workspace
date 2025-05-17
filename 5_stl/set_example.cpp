#include <iostream>
#include <set>
#include <unordered_set>    

int main() {
    std::set<int> s = {1, 2, 3, 4, 5};
    s.insert(6); // Insert an element
    s.insert(3); // Duplicate, will not be added

    std::unordered_set<int> us = {10, 20, 30, 40, 50};
    us.insert(60); // Insert an element
    us.insert(30); // Duplicate, will not be added

    std::multiset<int> ms = {100, 200, 300, 400, 500};
    ms.insert(600); // Insert an element
    ms.insert(300); // Duplicate, will be added
    ms.insert(300); // Duplicate, will be added

    std::unordered_multiset<int> ums = {1000, 2000, 3000, 4000, 5000};
    ums.insert(6000); // Insert an element
    ums.insert(3000); // Duplicate, will be added
    ums.insert(3000); // Duplicate, will be added

    std::cout <<"Printing set which will only accept unique elements in sorted way"<< std::endl;
    for (int num : s) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout <<"Printing unordered set which will only accept unique elements but unsorted"<< std::endl;
    for (int num : us) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout <<"Printing multiset which will allow duplicate elements in sorted way"<< std::endl;
    for (int num : ms) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout <<"Printing unordered_multiset which will allow duplicate elements but unsorted"<< std::endl;
    for (int num : ums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
