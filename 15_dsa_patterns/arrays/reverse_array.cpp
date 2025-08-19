/*
Problem: Reverse an Array

Given an array of integers, reverse the array in-place.

Constraints:
1 <= N <= 10^5
-10^9 <= A[i] <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated integers

Output Format:
- A single line with N space-separated integers (the reversed array)

Sample Input:
4
1 2 3 4

Sample Output:
4 3 2 1
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {23, 54, 65, 76, 27, 55, 55};
    int first = 0; 
    int last = arr.size()-1;
    
    while (first < last) {
        std::swap(arr[first], arr[last]);
        first++;
        last--;
    }
    for(int i : arr)
        cout << i << " ";

}