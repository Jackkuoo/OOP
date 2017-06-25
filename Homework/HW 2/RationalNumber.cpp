#include<iostream>
#include"RationalNumber.h"
using namespace std;

RationalNumber:: RationalNumber(int n,int d){
    if(d<0){
        numerator=-n;
        denominator=-d;
    }
    if(d>0){
        numerator=n;
        denominator=d;
    }
    if(d=0){
        cout<<"this form was not allow!!!!"<<endl;
    }
}
RationalNumber::RationalNumber(){
    numerator=0;
    denominator=1;
}
ostream &operator<<(ostream &output,RationalNumber &p){
    output<< p.numerator <<'/'<< p.denominator <<endl;
return output;
}

RationalNumber RationalNumber::operator+(RationalNumber &p){
     RationalNumber temp(numerator*p.denominator+denominator*p.numerator,denominator*p.denominator);
return temp;
}

RationalNumber RationalNumber::operator-(RationalNumber &p){
    RationalNumber temp(numerator*p.denominator-denominator*p.numerator,denominator*p.denominator);
    return temp;
}

RationalNumber RationalNumber::operator*(RationalNumber &p){
    RationalNumber temp(numerator*p.numerator,denominator*p.denominator);
return temp;
}

RationalNumber RationalNumber::operator/(RationalNumber &p){
    RationalNumber temp(numerator*p.denominator,denominator*p.numerator);
return temp;
}

int RationalNumber::operator>(RationalNumber &p){
    if((numerator*p.denominator-denominator*p.numerator)>0){
        return 1;
    }
    else{
        return 0;
    }
}
   
int RationalNumber::operator<(RationalNumber &p){
     if((numerator*p.denominator-denominator*p.numerator)<0){
        return 1;
    }
    else{
        return 0;
    }
}
int RationalNumber::operator>=(RationalNumber &p){
     if((numerator*p.denominator-denominator*p.numerator)>=0){
        return 1;
    }
    else{
        return 0;
    }
}

int RationalNumber::operator<=(RationalNumber &p){
     if((numerator*p.denominator-denominator*p.numerator)<=0){
        return 1;
    }
    else{
        return 0;
    }
}

int RationalNumber::operator==(RationalNumber &p){
     if((numerator*p.denominator-denominator*p.numerator)==0){
        return 1;
    }
    else{
        return 0;
    }
}

int RationalNumber::operator!=(RationalNumber &p){
     if((numerator*p.denominator-denominator*p.numerator)!=0){
        return 1;
    }
    else{
        return 0;
    }
}


