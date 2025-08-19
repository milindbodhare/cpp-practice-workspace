/*
Problem: Remove Duplicates from Sorted Array

Given a sorted array, remove duplicates in-place and return new length.

Constraints:
1 <= N <= 10^5
-10^9 <= A[i] <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated sorted integers

Output Format:
- First line: Integer k (new length)
- Second line: k space-separated integers (array with duplicates removed)

Sample Input:
6
1 1 2 2 3 4

Sample Output:
4
1 2 3 4
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void removeDuplicates(int arr[], int n)
{
    set<int> st;
    for(int i = 0; i < n; ++i)
    {
        st.insert(arr[i]);
    }
    
    std::set<int>::iterator it = st.begin();
    for(size_t i = 0; i < st.size(); ++i){
        arr[i] = *it;
        ++it;
     }
    cout << st.size() <<"\n";
    int index = 0;
    for(auto element : st)
    {
        arr[index] = element;
        index++;
    }
        
    for(int i = 0; i < st.size(); ++i)
    {
        cout << arr[i] << " ";
    }
}

int removeDuplicatesInPlace(int arr[], int size)
{
    int i = 0;
    for(int j = 1; j < size; ++j)
    {
        if(arr[j] != arr[i])
        {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    //Approach 1
    removeDuplicates(arr, size);
    removeDuplicatesInPlace(arr, size);
}