/*
Problem: Find All Pairs with Given Sum

Given an array and a target sum, print all pairs of elements whose sum is equal to the target.

Constraints:
1 <= N <= 10^4
-10^4 <= A[i] <= 10^4
-10^4 <= Target <= 10^4

Input Format:
- First line: Integer N
- Second line: N space-separated integers
- Third line: Target sum

Output Format:
- Each line should contain a pair: A[i] A[j]
- Pairs should be printed in order of occurrence (i < j)

Sample Input:
5
1 5 7 -1 5
6

Sample Output:
1 5
7 -1
1 5
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void searchPairsWithGivenSum(vector<int>& arr, int target)
{
    unordered_map<int, int> seen;
    for(int i = 0; i < arr.size(); ++i)
    {
        int complement = target - arr[i];
        if (seen.count(complement))
        {
            for (int j = 0; j < i; ++j) {
                if (arr[j] == complement) {
                    std::cout << arr[j] << " " << arr[i] << std::endl;
                }
            }
        }
        seen[arr[i]]++; 
    }
}

int main()
{
    int sum = 6;
    vector<int> arr = {1, 5, 7, -1, 5};
    searchPairsWithGivenSum(arr, sum);
}