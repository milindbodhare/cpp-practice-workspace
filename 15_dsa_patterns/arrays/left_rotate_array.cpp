/*
Problem: Left Rotate Array by One Position

Given an array, rotate it left by one position.

Constraints:
1 <= N <= 10^5
-10^9 <= A[i] <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated integers

Output Format:
- N space-separated integers (rotated array)

Sample Input:
5
1 2 3 4 5

Sample Output:
2 3 4 5 1
*/

#include <iostream>
#include <vector>
#include <string>

void leftRotate(std::string arr[], int n)
{
    std::string temp = arr[0];
    for(int i = 0; i < n-1; ++i)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;

    for(int i = 0; i < n-1; ++i)
    {
        std::cout << arr[i] << " ";
    }

}

int main()
{
    std::string arr[] = {"R", "A", "C", "E", "C", "A", "R"};
    int size = sizeof(arr)/sizeof(arr[0]);
    leftRotate(arr, size);
    return 0;
}