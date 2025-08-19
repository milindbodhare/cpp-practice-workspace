/*
Problem: Check if Array is Sorted

Given an array, check whether it is sorted in non-decreasing order.

Constraints:
1 <= N <= 10^5
-10^9 <= A[i] <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated integers

Output Format:
- "YES" if sorted, otherwise "NO"

Sample Input:
4
1 2 2 3

Sample Output:
YES
*/
#include <iostream>
#include <vector>

using namespace std;

bool isSorted(const vector<double>& v)
{
    //std::is_sorted(v.begin(), v.end()); //simplest using alogorithms
    for(int i = 0; i < v.size()-1; i++)
    {
        if(v[i] > v[i+1])
            return false;
    }
    return true;
}

int main()
{
    int size;
    cout << "Enter size : ";
    cin >> size;
    vector<double> v(size);
    for(double& element : v)
    {
        cin >> element; 
    }
    cout << (isSorted(v) ? "YES" : "NO") << endl;
    return 0;
}