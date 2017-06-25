#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area()=0;
protected:
    int color;
};
/* general class Point2D defined in lab9-2 */
class Point2D
{
public:
    int getx(){return x;}
    int gety(){return y;}
    Point2D(){ x = 0; y = 0; }
    Point2D(int a,int b){x=a; y=b;}
    void setPoint2D(int a,int b)
    {
        x=a; y=b;
    }
    void display() const
    {
        cout<<x<<','<<y<<endl;
    }
private:
    int x;
    int y;
};
class Polygon: public Shape
{
public:
    bool is_closed() { return true; }
};
class Triangle: public Shape
{
public:
    // constructor for Triangle
    Triangle(Point2D *v, int a)
    {
        vertices=new Point2D[3];
        vertices[0]=v[0];
        vertices[1]=v[1];
        vertices[2]=v[2];
        color=a;
    }
    Triangle(Point2D *v)
    {
        vertices=new Point2D[3];
        vertices[0]=v[0];
        vertices[1]=v[1];
        vertices[2]=v[2];
    }
    ~Triangle() { delete [] vertices; }
    void draw()
    {
        cout<<"Color: "<<color<<endl;
        cout<<"Vector: "<<endl;
        vertices[0].display();
        vertices[1].display();
        vertices[2].display();

    }
    double area()
    {
    double answer;
    answer=(vertices[0].getx()*vertices[1].gety()+vertices[1].getx()*vertices[2].gety()+vertices[2].getx()*vertices[0].gety()-vertices[1].getx()*vertices[0].gety()-vertices[2].getx()*vertices[1].gety()-vertices[0].getx()*vertices[2].gety())/2;
    if(answer<1)
    answer=-1*answer;
    return answer;
    }

private:
    Point2D *vertices;
};


class Circle: public Shape
{
public:
 Circle(Point2D a,int b){center=a,radius=b;}
 void draw(){cout<<"Center: ";
             center.display();
             cout<<"Radius: "<<radius<<endl;
            }
 double area(){return radius*radius*3.14;}
private:
 Point2D center;
 double radius;
};

class Rectangle:public Shape
{
    public:
    Rectangle(Point2D *v)
    {
        vertices=new Point2D[4];
        vertices[0]=v[0];
        vertices[1]=v[1];
        vertices[2]=v[2];
        vertices[3]=v[3];
    }
    double area()
    {
        double length,high;
        length=vertices[1].getx()-vertices[0].getx();
        high=vertices[2].gety()-vertices[1].gety();
        return length*high;

    }
    private:
    Point2D *vertices;

};

int main()
{
    Point2D pt(3,4);
    Circle cir(pt, 5);
    Point2D *vec = new Point2D [3];
    vec[0].setPoint2D(1,1);
    vec[1].setPoint2D(1,6);
    vec[2].setPoint2D(8,1);
    Triangle tri(vec);
    delete []vec;
    vec = new Point2D [4];
    vec[0].setPoint2D(1,1);
    vec[1].setPoint2D(6,1);
    vec[2].setPoint2D(6,6);
    vec[3].setPoint2D(1,6);
    Rectangle rect(vec);
    delete [] vec;
    Shape *collection[3];
    collection[0] = &cir;
    collection[1] = &tri;
    collection[2] = &rect;
    cout << "Area of Circle: " << collection[0]->area()
    << endl;
    cout << "Area of Triangle: " << collection[1]->area()
    << endl;
    cout << "Area of Rectangle: " << collection[2]->area()
    << endl;
    return 0;
}
