#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;


int main(int argc, char* argv[])
{
    ifstream fin;
    fin.open(argv[1], ios::in);
    ofstream fout;
    char* output;
    output = new char[strlen(argv[1])-3];
    for (int edx = 0;edx < strlen(argv[1])-4;edx++) 
        output[edx] = argv[1][edx];
    fout.open(output, ios::out);
    delete [] output;
    string jack;
    int a;
    while (fin >> jack)
    {
        a = atoi(jack.c_str());
        fin >> jack;
        for (int edx = 0;edx < a;edx++)
            fout << jack << " ";
    }
    fout << endl;
}
