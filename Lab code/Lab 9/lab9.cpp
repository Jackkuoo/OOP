#include <iostream>
#include "triangle.h"
#include "circle.h"
#include "point2d.h"
#include "circleintriangle.h"
using std::cout; using std::endl;
using namespace std;
int main()
{
    int a,b;
    point2d p;
//    point2d *vec = new point2d [3];
    int vec[]={1,1,3,1,1,6};
    //circleintriangle ct(p, 0, vec);
    p.setx(2);
    p.sety(2);
    circleintriangle ct(p,1, vec);
    cout << "Area of Circle: " << ct.circle::draw() << endl;
    cout << "Area of Triangle: " << ct.triangle::draw() <<
    endl;
       cout << "Area of Circle_in_Triangle: " << ct.area() <<
    endl;
    return 0;
}
