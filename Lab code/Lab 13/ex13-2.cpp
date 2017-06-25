#include<iostream>
#include<fstream>
#include<set>
#include<algorithm>
using namespace std;
int main(int argc,char* argv[]){
    ifstream inf(argv[1]);
    ofstream outf(argv[2]);
    set<string> name;
    int i,j;
    string a;
    while(getline(inf,a,'\n')){
        name.insert(a);
//        for(j=0;j<100;j++)a[j]='\0';
        i++;
    }
    set<string>::const_iterator iter;
    for(iter=name.begin();iter!=name.end();iter++){
        outf<<*iter<<endl;
    }
return 0;
}
        
