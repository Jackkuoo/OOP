#include<iostream>
#include<iomanip>
#include "Complex.h"
using namespace std;

void Complex::printComplex()
{
    cout << fixed << setprecision(1);
    cout << "(" << real << ", " << image << ")";
}
Complex Complex::add(Complex &b)
{
    Complex c(real + b.real, image + b.image);
    return c;
}

