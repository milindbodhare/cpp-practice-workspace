#include <iostream>

using namespace std;


class Base
{
    public:
    virtual void show() {cout << "Base::show";}
    virtual void login() {cout << "Base::login";}
};

class Derived : public Base
{
    public:
    void show() override {cout << "Derived::show" << endl;}
    void login(Base* obj){cout << "Derived::login" << endl;}
};

int main()
{
    Base* b;
    Base* bb;
    Derived* d;
    //b = new Derived();
    //b->show();
    //d = b; 
    //d->login(bb);
}