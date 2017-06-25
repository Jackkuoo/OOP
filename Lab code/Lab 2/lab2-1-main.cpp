#include <iostream>
#include "lab2-1.h"
using namespace std;

int main()
{
    Cplex a,b;
    readcomplex(a,b);
    Cplex results[4];
    results[0]=complexOperation(a,b,'+');
    results[1]=complexOperation(a,b,'-');
    results[2]=complexOperation(a,b,'*');
    results[3]=complexOperation(a,b,'/');
    printfComplex(results);
    return 0;
}
