#include <iostream>
using namespace std;

class point2d{
public:
    void display();
    point2d(int a,int b);
    int getx();
    int gety();
    void setx(int a);
    void sety(int a);
private:
    int *x;
    int *y;
};

class point4d:public point2d{
public:
    void display();
    point4d(int a,int b,int c,int d);
    int gett();
    int getz();
    void operator=(point2d &p);
private:
    int *z;
    int *t;
};
void point4d::operator=(point2d &p){
    //point4d s(p.getx(),p.gety(),0,0);
    setx(p.getx());
    sety(p.gety());
    *z=0;
    *t=0 ;
}
void point2d::setx(int a){
    *x=a;
}
void point2d::sety(int a){
    *y=a;
}

void point2d::display(){
    cout<<getx()<<'/'<<gety();
}
int point2d::getx(){
    return *x;
}
int point2d::gety(){
    return *y;
}
int point4d::getz(){
    return *z;
}
int point4d::gett(){
    return *t;
}
point2d::point2d(int a,int b){
    x=new int;
    *x=a;
    y=new int;
    *y=b;
}

void point4d::display(){
    point2d::display();
     cout<<'/'<<getz()<<'/'<<gett();
}

point4d::point4d(int a,int b,int c,int d):point2d(a,b){
    //x=new int;
    //y=new int;
    z=new int;
    *z=c;
    t=new int;
    *t=d;
}

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
    //pt4 could be (1,2,7,8) or (1,2,0,0)
    pt4.display(); cout << endl;
    return 0;
}
