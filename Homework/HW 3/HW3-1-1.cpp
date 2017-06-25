#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

void jackcout(ofstream &out, int a, string codeblock)
{
    if (a < 10){
        out <<"0"<< a << " " << codeblock << " ";}
    else{
        out << a << " " << codeblock << " ";}
}

int main(int argc, char* argv[])
{
    ifstream fin;
    fin.open(argv[1], ios::in);
    ofstream fout;
    fout.open(strcat(argv[1], ".rle"), ios::out);
    string love, yep;
    int counter = 1;
    fin >> love;
    yep = love;
    while (fin >> love)
    {
        if (love == yep){ 
            counter++;} 
        else
        {
            jackcout(fout, counter, yep);
            yep = love;
            counter = 1;
        }
    }
    jackcout(fout, counter, yep);
    fout << endl;
}


