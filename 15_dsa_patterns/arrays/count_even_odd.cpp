/*
Problem: Count Even and Odd Elements

Given an array, count the number of even and odd elements.

Constraints:
1 <= N <= 10^5
0 <= A[i] <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated integers

Output Format:
- Two space-separated integers: count_even count_odd

Sample Input:
5
1 2 3 4 5

Sample Output:
2 3
*/

#include <iostream>
#include <vector>

using namespace std;

void countEvenOdd(vector<int> v)
{
    int evenCount = 0, oddCount = 0;
    for(int i : v)
    {
        if(i % 2 == 0)
            ++evenCount;
        else
            ++oddCount;
    }
    cout << "Even : "<<evenCount << " Odd : "<<oddCount << endl;
}

int main()
{
    vector<int> v = {1, 2, 1, 6, 5, 7, 3};
    countEvenOdd(v);
}