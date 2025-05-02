#include <iostream>
using namespace std;

// Function declaration
int add(int a, int b);
void printMessage(string message);

// Function definition
int add(int a, int b) {
    return a + b;
}
void printMessage(string message) {
    cout << message << endl;
}

// Inline function
inline int square(int x) {
	return x * x;
}

int main() {
   // Function call
    int sum = add(5, 10);
    cout << "Sum: " << sum << endl;

    printMessage("Hello, World!");

    int num = 5;
    // Calling inline function
	int res = square(num);
	cout << "result is : " <<res << endl;

    return 0;
}