#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
    public:
        void assign(double,double);
        void assignReal(double);
        void assignImage(double);
        void printComplex();
        Complex add(Complex);
        Complex subtract(Complex);
        Complex multiply(Complex);
        Complex division(Complex);
    private:
        double real;
        double image;
};
#endif






