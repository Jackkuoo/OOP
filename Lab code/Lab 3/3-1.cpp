#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char string1[100],string2[100];
    int i,len1,len2;
    cout << "Enter first string:";
    cin >> string1;
    cout <<"Enter second string:";
    cin >> string2;
    len1=strlen(string1);
    len2=strlen(string2);
    if(strcmp(string1,string2)==0)
    {
        cout<< "The value returned from stringComparel(\""
        << string1
        << "\",\""<<string2<<"\") is 0"
        <<"\nThe value returned from stringCompare2(\""
        << string1
        << "\",\""<<string2<<"\") is 0"
        <<'\n';
    }
    else
    {
        if(len1==len2)
        {
            cout<< "The value returned from stringComparel(\""
            << string1
            << "\",\""<<string2<<"\") is 1"
            <<"\nThe value returned from stringCompare2(\""
            << string1
            << "\",\""<<string2<<"\") is 1"
            <<'\n';
        }
        else
        {
            cout<< "The value returned from stringComparel(\""
            << string1
            << "\",\""<<string2<<"\") is -1"
            <<"\nThe value returned from stringCompare2(\""
            << string1
            << "\",\""<<string2<<"\") is -1"
            <<'\n';
        }
    }
    return 0;
}
