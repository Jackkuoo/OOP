#include <iostream>
#define SIZE 10
using namespace std;
float selectionSort
int main()
{
    int i,j,m;
    int a[SIZE]={2,9,10,1,7,3,4,5,8,6};
    float b[SIZE]={2.2,9.9,10.1,1.1,7.7,3.3,4.4,5.5,8.8,6.6};
    cout<<"int data items in original order:\n";
    for(i=0;i<=10;i++)
    {
        cout<< a[i] <<" ";
        cout<<endl;
    }
    for(i=0;i<=10;i++)
    {
        for(j=0;j<=10;j++)
        {
            m=a[i];
            
