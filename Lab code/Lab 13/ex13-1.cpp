#include<iostream>
#include<vector>
#include<cstdlib> 
#include<algorithm>
#include<iterator>
using namespace std;

class Complex{
public:
    void randset(){
            //srand(time (NULL));
        r=rand()%10+0.1*(rand()%10);
        i=rand()%10+0.1*(rand()%10);
        l=r*r+i*i;
        }
     
    double getl(){return l;}
    double getr(){return r;}
    double geti(){return i;}
private:
    double r,i,l;
};

bool operator<(Complex &a,Complex &b){
    if(a.getl()>b.getl())return true;
return false;
}


void print(int n,vector<Complex> &s){
    int i;
    for(i=0;i<n;i++){
        cout<<'('<<s[i].getr()<<','<<s[i].geti()<<')';
    }
}
int main(){
    int n,i,j;
    srand(time(NULL));
    cout<<"enter n:";
    cin>>n;
    vector<Complex> os(n);
    for(i=0;i<n;i++){
        os[i].randset();
    }
    cout<<"Original sequence:";
    print(n,os);
    sort(os.begin(),os.end());

    cout<<"\nSorted sequence:";
    print(n,os);
return 0;
}
