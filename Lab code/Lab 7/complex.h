#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H
using namespace std;
class Complex
{
    friend Complex operator-(Complex);
    friend void printMeg(Complex,Complex,char);
    friend ostream &operator <<(ostream &output,const Complex &a);
public:
    Complex(double,double);
    Complex();
    Complex(const Complex &c);
    void setComplexNumber(double a,double b);
    void assignReal(double);
    void assignImage(double);
    //void printComplex();
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);
private:
    double real;
    double image;
};
//Complex::Complex()
//{
//    real=0;
//    image=0;
//}

#endif    
