#include <iostream>
#include "point2d.h"
#include "point4d.h"
using std::cout; using std::endl;
int main()
{
point2d pt1(1,2);
point2d pt2(3,4);
pt1.display(); cout << endl;
pt2.display(); cout << endl;
pt2 = pt1;
pt2. display(); cout << endl;
//cout<<"before";
point4d pt4(5,6,7,8);
//cout<<"after";
pt4.display(); cout << endl;
pt2 = pt4;
pt2.display(); cout << endl;
pt4 = pt1;
//pt4 could be (1,2,7,8) or 1,2,0,0)
pt4.display(); cout << endl; 
return 0;
}
