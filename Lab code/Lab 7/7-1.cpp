#include <iostream>
using namespace std;
#include "complex.h"
int main()
{
    Complex a(1.0,7.0),b(9.0,2.0),c;
    printMeg(a,b,'+');
    c=a+b;
    cout<<c<<endl;
    printMeg(a,b,'-');
    c=a-b;
    cout<<c<<endl;
    printMeg(a,b,'*');
    c=a*b;
    cout<<c<<endl;
    printMeg(a,b,'/');
    c=a/b;
    cout<<c<<endl;
    a.setComplexNumber(10.0,1.0);
    b=-a;
    printMeg(a,b,'-');
    c=a-b;
    cout<<c<<endl;
    return 0;
}
