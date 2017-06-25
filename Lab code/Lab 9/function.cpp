#include <iostream>
#include "point2d.h"
#include "circle.h"
#include "triangle.h"
#include "circleintriangle.h"

using namespace std;

void point2d::display(){
    cout<<' '<<x<<','<<y<<' '<<endl;
}
point2d::point2d(){
    x=0;y=0;
}
point2d::point2d(int a,int b){
    x=a;y=b;
}
int point2d::getx(){
    return x;
}
int point2d::gety(){
    return y;
}
void point2d::setx(int a){
    x=a;
}
void point2d::sety(int a){
    y=a;
} 
//triangle::~triangle(){ delete [] vertices; }

void circleintriangle::draw(){
    circle::draw();
    triangle::draw();
}

circleintriangle::circleintriangle(point2d &p,int r,int v[]){
    int i;
    
    setr(r);        
    setc(p);
    //ver=new point2d [3];
    setv(v);
}
double circle::draw(){
    double k=3.1415926*radius*radius;
    return k;
}
void circle::setr(int r){
    radius=r;
}
void circle::setc(point2d &p){
    center.setx(p.getx());
    center.sety(p.gety());
}
double triangle::draw(){
    double k,h,j;
    k=(ver[0].getx()*ver[1].gety())+
    (ver[1].getx()*ver[2].gety())+
    (ver[2].getx()*ver[0].gety());
    j=(ver[1].getx()*ver[0].gety())+
    (ver[2].getx()*ver[1].gety())+
    (ver[0].getx()*ver[2].gety());
    h=(k-j)/2;
    return h;
}
void triangle::setv(int v[]){
   // ver=new point2d [3];
    ver=new point2d [3];
    int i;
    for(i=0;i<3;i++){
        ver[i].setx(v[2*i]);
        ver[i].sety(v[2*i+1]);
    }
}   

double circleintriangle::area(){
    double k=triangle::draw()-circle::draw();
    return k;
}

