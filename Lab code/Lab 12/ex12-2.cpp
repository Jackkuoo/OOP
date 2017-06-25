#include <iostream>
#include <fstream>
#include <cstring>
#include<stdio.h>
#include<stdio.h>
using namespace std;
int main (int argc,char *argv[]){
    char *fm=argv[1];
    ifstream infile(fm);
    string tex;
    int cb=0,i,j,l,cs=0;
    l=strlen(argv[2]);
    while(getline(infile,tex,'\n')){
        for(i=0;i<40;i++){
            for(j=0;j<l;j++){
                if(tex[i+j]==argv[2][j])
                    cs++;
            }
            
            if(cs==l){
                cb++;
            }
            cs=0;
        };//cout<<cb;
   // cout<<endl;
    tex="                                                   ";
    }
    //if(cb==-1)cb=0;
    cout<<endl<<argv[2]<<" appears "<<cb<<" time(s)";
infile.close();
return 0;
}
