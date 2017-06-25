#include<iostream>
#include<iomanip>
#include "IntegerSet.h"
using namespace std;

int * IntegerSet::getnumber(const IntegerSet &s){
    int x=0,i=0,j=0;
    int *u;
    u=new int [10];
    while(i<10){
        u[x]=-2;
        for(j=0;j<=100;j++){
            if(s.a[i][j]==1){
                u[i]=j;
                i++;
                x++;
                break;
            }
            if(j==100){
                i++;
            }
        }
    }
    x=0;i=0;j=0;
    return u;
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet s){
    int i=0,x=0,j=0,*u1,*u2,l1=0,l2=0;
    u1=getnumber(*this);
    u2=getnumber(s);

    for(l1=0;;l1++){
        if(u1[l1]==-2){
            break;
        }
    }
    for(l2=0;;l2++){
        if(u2[l2]==-2){
            break;
        }
    }
    for(i=0;i<l1;i++){
        for(j=0;j<l2;j++){
            if(u1[i]==u2[j]){
                break;
            }
            if(j==l2-1){
                u2[l2]=u1[i];
                l2++;
            }
        }
    }
    IntegerSet k(u2,l2);
    return k;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet s){
    int i=0,x=0,j=0,*u1,*u2,*intersection,l1=0,l2=0;
    u1=getnumber(*this);
    u2=getnumber(s);
    intersection=new int [10];
    for(l1=0;;l1++){
        if(u1[l1]==-2){
            break;
        }
    }
    for(l2=0;;l2++){
        if(u2[l2]==-2){
            break;
        }
    }

for(i=0;i<l1;i++){
    cout<<u1[i]<<'*';
}cout<<endl;
for(i=0;i<l2;i++){
    cout<<u2[i]<<'*';
}cout<<endl;


    for(i=0;i<l1;i++){
        for(j=0;j<l2;j++){
            if(u1[i]==u2[j]){
                intersection[x]=u1[i];
                x++;
                break;           
            }
        }
    }
    IntegerSet g(intersection,x);
    return g;
}

void IntegerSet::insertElement(int k){
    int i,j,count=0;
    for(i=0;i<10;i++){
        count=0;
        for(j=0;j<=100;j++){
            if(a[i][j]==1){
                count++;
            }           
        }
        if(count==0){
            a[i][k]=1;
            break;
        }
    }
}
   
void IntegerSet::deleteElement(int k){
    int i;
    for(i=0;i<10;i++){
        if(a[i][k]==1){
            a[i][k]=0;
        }
    }
}


ostream &operator<<(ostream &output,IntegerSet &p){
    int i,j;
    output<<'{';
    for(i=0;i<10;i++){
        for(j=0;j<=100;j++){
            if(p.a[i][j]==1){
                output<<' '<<j<<' ';
            }
        }
    }
    output<<'}'<<endl;
return output;
}

istream &operator>>(istream &input, IntegerSet &p){
    int i=0,j=0;
    while(j!=-1){
        cout<<"Enter an element (-1 to end):";
        input>>setw(1)>>j;
        input.ignore(1);
        cout<<endl;
        if(j==-1){
            cout<<"Entry complete\n";
            return input;
        }
        else if(j>100||j<-1){
            cout<<"Invalid Element"<<j<<endl;
        }
        else{
            p.a[i][j]=1;
            i++;
        }   
    }
}

int IntegerSet::isEqualTo(IntegerSet s){
    int i,j,h[10],g[10],gtoh,htog;
    for(i=0;i<10;i++){
        for(j=0;j<=100;j++){
            if(a[i][j]==1){
                h[i]=j;
            }
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<=100;j++){
            if(s.a[i][j]==1){
                g[i]=j;
            }
        }
    }
    for(i=0;i<10;i++){
        htog=0;
        gtoh=0;
        for(j=0;j<10;j++){
            if(h[i]==g[j]){
                htog++;
            }
            if(g[i]==h[j]){
                gtoh++;
            }
        }
        if(htog==0||gtoh==0){
            return 0;
        }   
    }
return 1;
}
    

IntegerSet::IntegerSet(){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<=100;j++){
            a[i][j]=0;
        }
    }
}

IntegerSet::IntegerSet(int k[],int size){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<=100;j++){
            a[i][j]=0;
        }
    }
    for(i=0;i<size;i++){
        if(k[i]>100||k[i]<0){
            cout<<"Invalid Element "<<k[i]<<endl;
        }
        else{
            a[i][k[i]]=1;
        }
    }
}




