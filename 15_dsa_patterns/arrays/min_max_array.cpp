/*
Problem: Find Maximum and Minimum in an Array

Given an array of integers, find the maximum and minimum element in the array.

Constraints:
1 <= N <= 10^5
-10^9 <= A[i] <= 10^9

Input Format:
- First line: Integer N (size of array)
- Second line: N space-separated integers A[i]

Output Format:
- Two space-separated integers: max_element min_element

Sample Input:
5
3 -1 4 1 5

Sample Output:
5 -1
*/


#include <iostream>
#include <limits.h>
using namespace std;

void findMinMax(int arr[], int size)
{
    int minNumber = arr[0], maxNumber = arr[0];

    for(int i = 1; i < size; ++i)
    {
        if(arr[i] > maxNumber)
            maxNumber = arr[i];
        if(arr[i] < minNumber)
            minNumber = arr[i];
    }
    cout << maxNumber << " " << minNumber;
}

int main()
{
    int size = 0; 
    cout << "Enter size of Array : " <<endl;
    cin >> size;
    int arr[size];

    for(int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    findMinMax(arr, size);
}