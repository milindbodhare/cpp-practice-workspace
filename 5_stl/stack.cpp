#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> stk;
    stk.push('M');
    stk.push('I');
    stk.push('L');
    stk.push('I');
    stk.push('N');
    stk.push('D');

    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}