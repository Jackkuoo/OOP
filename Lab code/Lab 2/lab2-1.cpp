#include <iostream>
#include "lab2-1.h"
using namespace std;

void readcomplex(Cplex &a,Cplex &b)
{
    char i;
    cout<<"First complex number:";
    cin>>a.real>>a.image>>i;
    cout<<"Second complex number:";
    cin>>b.real>>b.image>>i;
}
Cplex complexOperation(Cplex &a,Cplex &b,char c)
{
    Cplex r;
    if(c=='+')
    {
        r.real=a.real+b.real;
        r.image=a.image+b.image;
    }
    if(c=='-')
    {
        r.real=a.real-b.real;
        r.image=a.image-b.image;
    }
    if(c=='*')
    {
        r.real=(a.real * b.real)-(a.image * b.image);
        r.image=(a.real * b.image)+(a.image * b.real);
    }
    if(c=='/')
    {
        r.real=((a.real * b.real)-(a.image * (-b.image)))/((a.real * a.real)+(b.image * b.image));
        r.image=(a.real * (-b.image))+(a.image * b.real)/((a.real * a.real)+(b.image * b.image));
    }
    return r;
}
void printfComplex(Cplex results[])
{
    cout<<"The output result\n";
    cout<<"A + B = "<<results[0].real;
    if(results[0].image<0)
        cout<<results[0].image<<"i\n";
    else
        cout<<"+"<<results[0].image<<"i\n";

    cout<<"A - B = "<<results[1].real;
    if(results[1].image<0)
        cout<<results[1].image<<"i\n";
    else
        cout<<"+"<<results[1].image<<"i\n";

    cout<<"A * B = "<<results[2].real;
    if(results[2].image<0)
        cout<<results[2].image<<"i\n";
    else
        cout<<"+"<<results[2].image<<"i\n";

    cout<<"A / B = "<<results[3].real;
    if(results[3].image<0)
        cout<<results[3].image<<"i\n";
    else
        cout<<"+"<<results[3].image<<"i\n";
}
