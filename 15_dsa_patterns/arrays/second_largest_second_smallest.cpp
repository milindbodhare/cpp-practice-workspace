/*
Problem: Find Second Largest and Second Smallest

Given an array, find the second largest and second smallest element.

Constraints:
2 <= N <= 10^5
-10^9 <= A[i] <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated integers

Output Format:
- Two space-separated integers: second_largest second_smallest
- If not possible, print -1 -1

Sample Input:
5
5 1 3 4 2

Sample Output:
4 2
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int findSecondLargest(vector<int>& vctr)
{
    int largest = vctr[0];
    int sLargest = INT_MIN;
    for(int i = 1; i < vctr.size(); ++i)
    {
        if(vctr[i] > largest)
        {
            sLargest = largest;
            largest = vctr[i];
        }
        else if(vctr[i] < largest && vctr[i] > sLargest)
        {
            sLargest = vctr[i];
        }
    }
    return sLargest;
}
int findSecondSmallest(vector<int>& vctr)
{
    int smallest = vctr[0];
    int sSmallest = INT_MAX;
    for(int i = 1; i < vctr.size(); ++i)
    {
        if(vctr[i] < smallest)
        {
            sSmallest = smallest;
            smallest = vctr[i];
        }
        else if(vctr[i] > smallest && vctr[i] < sSmallest)
        {
            sSmallest = vctr[i];
        }
    }
    return sSmallest;
}

void findElementAfterSorting(vector<int>& v1)
{
    std::sort(v1.begin(), v1.end());

    // Find Second Largest
    int largest = v1.back(); // Get the last element (largest after sorting)
    int sLargest = -1;
    for(int i = v1.size()-2; i != 0; --i)
    {
        if(v1[i] != largest){
            sLargest = v1[i];
            break; // Found the second largest distinct element
        }
    }
    // Find Second Smallest
    int smallest = v1[0];
    int secondSmallest = -1;
    for (size_t i = 1; i < v1.size(); ++i) {
        if (v1[i] > smallest) {
            secondSmallest = v1[i];
            break;
        }
    }
            
}

vector<int> findElementsInPlace(vector<int>& v)
{
    int secondLargest = findSecondLargest(v);
    int secondSmallest = findSecondSmallest(v);
    return {secondLargest, secondSmallest};
}

int main()
{
    int size;
    cout << "Enter size of array : ";
    cin >> size;
    //int arr[size];
    //int* arr = new int[size];
    vector <int> arr(size);
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    //Approach 1 (sort & find)
    findElementAfterSorting(arr);

    //Apporach 3 (optimal)
    vector<int> v = findElementsInPlace(arr);
    for(int i : v)
        cout << i <<" ";
}