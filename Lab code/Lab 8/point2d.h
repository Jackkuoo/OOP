#ifndef POINT2D_H
#define POINT2D_H
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

#endif

