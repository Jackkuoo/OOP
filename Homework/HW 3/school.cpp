#include<iostream>
#include"score.txt"
#include"school.txt"
#include<fstream>
#include<string>
using namespace std;

student::student(){}

int school::report(char* a){
    ofstream fout;
    fout.open(a);
    double k=0,yosemite=0,avg=0,times=0;
    for(int i=0;i<10;i++){
        if(p.getid(i)==0){
            break;
        }
        fout<<p.getid(i)<<' ';
        for(int j=0;j<20;j++){
            if(p.getname(i,j)=='\0'){
            break;
            }
            fout<<p.getname(i,j);
        }
        fout<<' ';
        for(int j=0;j<20;j++){
            if(t.getpoint(i,j)==0){
                times=j;
                break;
            }
            yosemite+=t.getpoint(i,j);
        }
        if(times==0){
            break;
        }
        k=s.getit(i);
        avg+=yosemite/(times+(5*k));
        fout<<yosemite/(times+(5*k))<<'\n';
        yosemite=0;
    }
    int i;
    fout<<"Average: "<<avg/i;
    fout.close();
}

school::school(char *a){
    ifstream fin;
    fin.open(a);
    int i,j,k,m=0,yosemite;
    char string;
    fin>>k;
    fin>>yosemite;
    for(i=0;i<=k;i++) p.setid(i,0);
    for(i=0;i<k;i++){
        s.deter(i);
        p.setid(i,yosemite);
        for(j=0;j<20;j++){
            fin>>string;
            if(string<=58){               
                p.setname(i,j,'\0');
                fin.putback(string);
                break;
            }
            p.setname(i,j,string);
        }
        m=0;
        for(j=0;j<30;j++){
            fin>>yosemite;
            if(yosemite==0){
            }
            if(yosemite==1){
                s.trace(i);
            }
            if(yosemite>2&&yosemite<101){
                t.setpoint(i,m,yosemite);
                m++;
            }
            if(yosemite>200||fin.fail())break;           
        }
    }
    fin.close();
}
int student::getid(int n){
    return id[n];
}
char student:: getname(int n,int i){
    return name[n][i];
}
void student::setid(int n,int d){
    id[n]=d;
}
void student:: setname(int n,int i,char y){
    name[n][i]=y;
}
