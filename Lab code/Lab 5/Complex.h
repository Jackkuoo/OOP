#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
private:
    double real;
    double image;
public:
    Complex() {}
    Complex(double r, double i) : real(r), image(i) {}
    Complex(Complex &cp) {real = cp.real; image = cp.image;}
    ~Complex() {}
    void printComplex();
    Complex add(Complex&);
};

#endif

