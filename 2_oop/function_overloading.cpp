#include <iostream>

using namespace std;

class Sample
{
    public:
    void printData(int a) { cout << "data is : "<< a << endl;}
    void printData(double a) { cout << "same number of args different data type = data is : "<< a << endl;}
    void printData(int a, double b) { cout << "different number of args different/same data type = data is : "<< a <<" "<< b << endl;}

    void printData(double c, int d) { cout << "same number of args different data type = data is : "<< c <<" "<< d << endl;}

    //will give compiler error //function overloading is not supported with return type
    // int printData(int b) {
    //     cout << "data is : "<< b << endl; 
    //     return 0;
    // }
};


int main(){
    Sample s;
    s.printData(5);
    s.printData(21.4);
    s.printData(6, 10.5);
    s.printData(99.99, 777);

return 0;
}