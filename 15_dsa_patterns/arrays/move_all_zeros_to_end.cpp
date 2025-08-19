/*
Problem: Move All Zeros to End

Given an array, move all zeroes to the end while maintaining the relative order of non-zero elements.

Constraints:
1 <= N <= 10^5
-10^9 <= A[i] <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated integers

Output Format:
- A single line with modified array

Sample Input:
6
0 1 0 3 12 0

Sample Output:
1 3 12 0 0 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveAllZeros(vector<int>& vctr)
{
    vector<int> result;
    int zeroCount = 0;
    for(int i = 0; i < vctr.size(); ++i)
    {
        if(vctr[i] != 0)
            result.push_back(vctr[i]);
        else
            ++zeroCount;
    }
    for(int i = 0; i < zeroCount; ++i)
        result.push_back(0);
    for(int i : result)
        cout << i << " ";
}

void moveAllZerosInPlace(vector<int>& vctr)
{
    int left = 0;
    for(int right = 0; right < vctr.size(); ++right)
    {
        if(vctr[right] != 0)
        {
            std::swap(vctr[left], vctr[right]);
            left++;
        }
    }
    for(int i : vctr)
        cout << i << " ";
}

int main()
{
    vector<int> v = {1, 0, 0, 2, 3, 4, 0, 3, 0};
    //Approach 1 with extra space
    moveAllZeros(v);
    //Approach 2 with no extra space
    moveAllZerosInPlace(v);
}