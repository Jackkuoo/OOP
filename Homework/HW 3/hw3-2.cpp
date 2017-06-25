#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream fin;
    fin.open(argv[1], ios::in);
    if(fin.fail()){
        cout<<"error\n";
        return 1;
    }
    string s,p;
    int k=0,length=0;
    while(fin>>s){
        if(length<=s.size()){
            length=s.size();
            p=s;    
        }
        k+=1;
    }
    ofstream fout(argv[2]);
    fout<<"The number of word read is "<<k<<endl;
    fout<<"The longest word has a length of "<<length<<endl;
    fout<<"The longest word is"<<p<<endl;
    fin.close();
    return 0;
}
