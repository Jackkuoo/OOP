#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Point2D{
public:
    void setx(int a){x=a;}
    void sety(int b){y=b;}
    int getx(){return x;}
    int gety(){return y;}
private:
	int x;
	int y;
};


template<class T>
T *new1D(int n,int k=0){
	T *vec=new T[n];
	//	for(int i=0;i<n;i++);
	//		vec[i]=k;
	return vec;
}

template<class T>
void rand1D(T *a,int k){
	//for(int i=0;i<n;i++){
	//	a[i]=rand()%10+1;
	//}
}

template<>
void rand1D(int*a,int k){
	for(int i=0;i<k;i++){
		a[i]=rand()%10+1;
	}
}

template<>
void rand1D(double*a,int k){
	for(int i=0;i<k;i++){
		a[i]=rand()%1001/100.0;
	}
}

template<>
void rand1D(char*a,int k){
	for(int i=0;i<k;i++){
		a[i]=97+rand()%26;
	}
}

template<>
void rand1D(Point2D*a,int k){
	for(int i=0;i<k;i++){
		a[i].setx(rand()%10+1);
		a[i].sety(rand()%10+1);
	}
}

template<class T>
void display1D(T *a,int k){
	for(int i=0;i<k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

template<>
void display1D(int *a,int k){
	for(int i=0;i<k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

template<>
void display1D(double *a,int k){
	for(int i=0;i<k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

template<>
void display1D(char *a,int k){
	for(int i=0;i<k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

template<>
void display1D(Point2D *a,int k){
	for(int i=0;i<k;i++){
		cout<<"("<<a[i].getx()<<","<<a[i].gety()<<")"<<" ";
	}
	cout<<endl;
}

template<class T>
void sort1D(T *a,int k){
	T max=0;
	for(int i=0;i<k-1;i++){
		for(int j=0;j<k-1;j++){
			if(a[j]>a[j+1]){
				max=a[j+1];
				a[j+1]=a[j];
				a[j]=max;
			}
		}
	}
}

template<>
void sort1D(int *a,int k){
	int max=0;
	for(int i=0;i<k-1;i++){
		for(int j=0;j<k-1;j++){
			if(a[j]>a[j+1]){
				max=a[j+1];
				a[j+1]=a[j];
				a[j]=max;
			}
		}
	}
}

template<>
void sort1D(double *a,int k){
	double max=0;
	for(int i=0;i<k-1;i++){
		for(int j=0;j<k-1;j++){
			if(a[j]>a[j+1]){
				max=a[j+1];
				a[j+1]=a[j];
				a[j]=max;
			}
		}
	}
}

template<>
void sort1D(char *a,int k){
	char max=0;
	for(int i=0;i<k-1;i++){
		for(int j=0;j<k-1;j++){
			if(a[j]>a[j+1]){
				max=a[j+1];
				a[j+1]=a[j];
				a[j]=max;
			}
		}
	}
}

template<>
void sort1D(Point2D *a,int k){
	Point2D max;
	for(int i=0;i<k-1;i++){
		for(int j=0;j<k-1;j++){
			if(a[j].getx()>a[j+1].getx()){
				max=a[j+1];
				a[j+1]=a[j];
				a[j]=max;
			}
			if(a[j].getx()==a[j+1].getx()){
				if(a[j].gety()==a[j+1].gety()){
					max=a[j+1];
					a[j+1]=a[j];
					a[j]=max;	
				}
			}
		}
	}
}

template<class T>
void analysis(int n,int k=0){
	T *vec = new1D<T> (n,k);
	rand1D<T>(vec,n);
	display1D<T>(vec,n);
	sort1D<T>(vec,n);
	display1D<T>(vec,n);
}
int main(){
int n;
cout<<"Enter n: ";
cin>>n;
srand(1);
analysis<int>(n);
analysis<double>(n);
analysis<char>(n);
analysis<Point2D>(n);
return 0;
}
