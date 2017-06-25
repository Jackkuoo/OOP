#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;


int main(int argc, char* argv[])
{
    ifstream in;
    in.open(argv[1], ios::in);
    ofstream out;
    char* outfile;
    outfile = new char[strlen(argv[1])-3];
    for (int idx = 0;idx < strlen(argv[1])-4;idx++) 
        outfile[idx] = argv[1][idx];
    out.open(outfile, ios::out);
    delete [] outfile;
    string proc;
    int num;
    while (in >> proc)
    {
        num = atoi(proc.c_str());
        in >> proc;
        for (int idx = 0;idx < num;idx++)
            out << proc << " ";
    }
    out << endl;
}
