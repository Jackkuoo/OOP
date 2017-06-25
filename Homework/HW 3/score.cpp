#include<iostream>
#include<string>
#include"score.txt"
#include"school.txt"
using namespace std;
test :: test(){
}
sport:: sport(){
}
evaluation::evaluation(){}
score::score(){}
double test:: getpoint(int n,int m){
    return point[n][m];
}
void test:: setpoint(int n,int m,double s){
    point[n][m]=s;
}
void sport::trace(int n){
    game[n]++;
}
void sport::deter(int n){
    game[n]=0;
}
int sport:: getit(int n){
    return game[n];
}
