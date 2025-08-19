/*
Problem: Sum of Array Elements

Given an array, calculate the sum of all elements.

Constraints:
1 <= N <= 10^5
-10^6 <= A[i] <= 10^6

Input Format:
- First line: Integer N
- Second line: N space-separated integers

Output Format:
- A single integer: sum of all elements

Sample Input:
3
10 20 30

Sample Output:
60
*/

#include <iostream>
#include <vector>

using namespace std;

void sumOfElements(vector<int> vctr)
{
    int result = 0;
    for(int i= 0; i < vctr.size(); i++)
        result += vctr[i];

    std::cout << "sum of elements : " << result << " ";
}

int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    vector<int> v(size);

    for(int i= 0; i < size; i++)
    {
        cin >> v[i]; 
    }
    sumOfElements(v);

}