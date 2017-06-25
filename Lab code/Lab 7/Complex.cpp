#include <iostream>
#include <stdio.h>
#include "complex.h"

using namespace std;

ostream &operator <<(ostream &output,const Complex &a)
{
    printf("%.1lf,%.1lf",a.real,a.image);
    return output;
}
Complex::Complex()
{
    real=0;
    image=0;
}
Complex::Complex(double r,double i)
{
    real=r;
    image=i;
}
Complex::Complex(const Complex &c)
{
    real=c.real;
    image=c.image;
}
void Complex::setComplexNumber(double a,double b)
{
    real=a;
    image=b;
}
void Complex::assignReal(double a)
{
    real=a;
}
void Complex::assignImage(double b)
{
    image=b;
}
/**void Complex::printComplex()
{
    cout<<'('<<real<<','<<image<<')';
}**/
Complex operator-(Complex a)
{
    Complex b;
    b.real-=a.real;
    b.image-=a.image;
    return b;
}
Complex Complex::operator+(Complex number)
{
    Complex A;
    A.real=real+number.real;
    A.image=image+number.image;
    return A;
}
Complex Complex::operator-(Complex number)
{
    Complex A;
    A.real=real-number.real;
    A.image=image-number.image;
    return A;
}
Complex Complex::operator*(Complex number)
{
    Complex A;
    A.real=real*number.real-image*number.image;
    A.image=image*number.real+real*number.image;
    return A;
}
Complex Complex::operator/(Complex b)
{
    Complex A;
    A.real=(real*b.real+image*b.image)/(b.real*b.real+b.image*b.image);
    A.image=(image*b.real-real*b.image)/(b.real*b.real+b.image*b.image);
    return A;
}
void printMeg(Complex a,Complex b,char o)
{
    printf("(%.1lf , %.1lf) %c (%.1lf , %.1lf) = ",a.real,a.image,o,b.real,b.image);  
}
