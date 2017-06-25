#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc,char *argv[])
{
    ifstream fin;
    fin.open(argv[1],ios::in);
    ofstream fout;
    fout.open(argv[2],ios::out);
    int number,id,sum=0,all=0,k;
    double average;
    string jack;
    fin >> number;
    //cout<<number<<endl;
    for(int i=0;i<number;i++){
        fin>>id>>jack;
        sum=all=0;
        for(int j=0;j<10;j++){
            if(j<=4){
                fin>>k;
                sum+=k;
            }
            else if(j>=5){
                fin>>k;
                all+=k;
            }
        }
        sum=sum/5;
        sum+=5*all;
        fout<<id<<"  "<<jack<<"  "<<sum<<endl;
        average+=sum;
    }
    average=average/5;
    fout<<"Average: "<<average<<endl;
    fin.close();
    return 0;
}
