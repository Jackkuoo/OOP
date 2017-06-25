#include<iostream>
#include "Complex.h"
using namespace std;


int main()
{
    Complex a(1.0, 7.0), b(9.0, 2.0), c; // create three Complex objects
    a.printComplex(); // output object a
    cout << " + ";
    b.printComplex(); // output object b
    cout << " = ";
     //invoke add function and assign to object c
    c = a.add(b);
    c.printComplex(); // output object c
    cout << endl;
    Complex d(c);
    d.printComplex(); // output object d
    cout << endl;

    return 0;
}

