/*
Problem: Rotate Array by K Positions (Left)

Given an array, rotate it to the left by K positions.

Constraints:
1 <= N <= 10^5
1 <= K <= N
-10^9 <= A[i] <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated integers
- Third line: Integer K

Output Format:
- N space-separated integers after rotation

Sample Input:
6
1 2 3 4 5 6
2

Sample Output:
3 4 5 6 1 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateArray(vector<int>& v, int k)
{
    int temp[k];
    for(int i = 0; i < k; ++i)
        temp[i] = v[i];
    
    for(int i = 0; i < (v.size()-k); ++i)
        v[i] = v[i+k];

    int j = 0;
    for(int i = (v.size()-k); i < v.size(); ++i)
    {
        v[i] = temp[j];
        j++;
    }

    for(int i : v)
    {
        cout << i << " ";
    }
        
}

int main()
{
    vector<int> v = {10,20,30,40,50,60};
    int toShiftBy = 2;
    rotateArray(v, toShiftBy);
}
