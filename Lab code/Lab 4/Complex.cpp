#include <iostream>
#include "complex.h"

using namespace std;

void Complex::assign(double a,double b)
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
void Complex::printComplex()
{
    cout<<'('<<real<<','<<image<<')';
}
Complex Complex::add(Complex number)
{
    Complex A;
    A.real=real+number.real;
    A.image=image+number.image;
    return A;
}
/**Complex Complex::subtract(Complex number)
{
    Complex A;
    A.real=real-number.real;
    A.image=image-number.image;
    return A;
}
Complex Complex::multiply(Complex number)
{
    Complex A;
    A.real=real*number.real-image*number.image;
    A.image=image*number.real+real*number.image;
    return A;
}
Complex Complex::division(Complex b)
{
    Complex A;
    A.real=(real*b.real+image*b.image)/(b.real*b.real+b.image*b.image);
    A.image=(image*b.real-real*b.image)/(b.real*b.real+b.image*b.image);
    return A;
}**/
