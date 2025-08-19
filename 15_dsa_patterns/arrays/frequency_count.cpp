/*
Problem: Count Frequency of an Element

Given an array and a number X, count how many times X appears in the array.

Constraints:
1 <= N <= 10^5
-10^9 <= A[i], X <= 10^9

Input Format:
- First line: Integer N
- Second line: N space-separated integers
- Third line: Integer X

Output Format:
- A single integer: frequency of X

Sample Input:
6
1 2 3 2 2 4
2

Sample Output:
3
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void frequencyCounter(vector<char> vctr)
{
    unordered_map<char, int> charFreq;
    for(char c : vctr)
    {
        charFreq[c]++;
    }
    // Print the character frequencies.
    std::cout << "Character Frequencies:\n";
    for (const auto& pair : charFreq) {
        std::cout << "'" << pair.first << "': " << pair.second << "\n";
    }
}

int main()
{
    vector<char> v = {'A','B','B','A','C','A','E'};
    frequencyCounter(v);

}