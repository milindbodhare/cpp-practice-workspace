/*Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'
Chech whether A has redundant braces or not.
Return 1 if A has redundant braces, else return 0.
Example Input
Input 1: A = "((a+b))"
 
Input 2:A = "(a+(a+b))"
 
Input 3:A = "((a*b)+(c+d))"
Example Output
Output 1:1
Output 2:0
Output 3:0*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool hasRedundentBraces(string& str) {
    stack<char> st;
    for(char ch : str)
    {
        if(ch == ')'){
            bool hasOperator = false;

            //pop till '(' and check for any operator
            while(!st.empty() && st.top() != '(') {
                char top = st.top();
                    if(top == '+' || top == '-' || top == '/' || top == '*') {
                        hasOperator = true;
                    }
                st.pop();
            }
             // Pop the '('
            if (!st.empty()) st.pop();
            // If no operator found → redundant
            if (!hasOperator) return 1;
        }
        else{
            st.push(ch);
        }
    }
    return 0;
}

int main()
{
     string input1 = "((a+b))";          // Redundant
    string input2 = "(a+(a+b))";        // Not redundant
    string input3 = "((a*b)+(c+d))";    // Not redundant
    string input4 = "(a)";              // Redundant
    string input5 = "(((a)))";          // Redundant

    cout << "Output 1: " << hasRedundentBraces(input1) << endl;
    cout << "Output 2: " << hasRedundentBraces(input2) << endl;
    cout << "Output 3: " << hasRedundentBraces(input3) << endl;
    cout << "Output 4: " << hasRedundentBraces(input4) << endl;
    cout << "Output 5: " << hasRedundentBraces(input5) << endl;

    return 0;
}