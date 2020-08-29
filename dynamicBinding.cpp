#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show() { cout << " In Base \n"; }
};

class Derived1 : public Base
{
public:
    void show() { cout << "In Derived1 \n"; }
};

class Derived2 : public Base
{
public:
    void show() { cout << "In Derived2 \n"; }
};

int main(void)
{
    Base *bp = new Base;
    bp->show();

    cout << "<<<    RUNTIME POLYMORPHISM    >>>" << endl;
    
    bp = new Derived1;
    bp->show();

    bp = new Derived2;
    bp->show();

    return 0;
}