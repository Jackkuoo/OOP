#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<string.h>
using namespace std;
int main(int argc,char *argv[]){
    int i,c,a[40];
    c=atoi(argv[1]);
    //for(i=0;i<argc;i++)cout<<argv[i]<<'%';
    //cout<<endl;
    for(i=2;i<argc;i+=2){
        if(strcmp(argv[i],"-")==0){          
            c=c-atoi(argv[i+1]);
        }
        if(strcmp(argv[i],"+")==0){
            c=c+atoi(argv[i+1]);
        }
    } 
    cout<<c<<endl;
return 0;
}
