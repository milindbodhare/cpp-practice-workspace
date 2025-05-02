#include <iostream>
using namespace std;

int main() {
    // Conditional statements
    int a = 10;
    if (a > 5) {
        cout << "a is greater than 5" << endl;
    } else {
        cout << "a is less than or equal to 5" << endl;
    }

    // Switch statement
    int day = 3;
    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        default:
            cout << "Invalid day" << endl;
    }
    // Looping statements
    int i;
    for (i = 0; i < 5; i++) {
        cout << "i: " << i << endl;
    }
    while (i < 5) {
        cout << "i: " << i << endl;
        i++;
    }

    return 0;
}