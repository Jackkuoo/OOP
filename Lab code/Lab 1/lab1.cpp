#include <iostream>
#define PI 3.14159
#define circleArea(x) (PI*(x)*(x))
int main()
{
    int n;
    std::cout<<"Enter the radius of the circle:";
    std::cin >>n;
    std::cout<<"The area of the circle is "
             <<circleArea(n)<<std::endl;
    return 0;
}
