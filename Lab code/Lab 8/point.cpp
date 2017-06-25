#include <iostream>
#include "point2d.h"
#include "point4d.h"
using namespace std;

void point4d::operator=(point2d &p){
    //point4d s(p.getx(),p.gety(),0,0);
    setx(p.getx());
    sety(p.gety());
    *z=0;
    *t=0;
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

