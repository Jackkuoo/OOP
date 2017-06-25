#include<string>
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
class HugeInteger
{
public:
    HugeInteger();
    HugeInteger(long);
    HugeInteger(std::string);
    HugeInteger(int);
    HugeInteger(HugeInteger&);
    HugeInteger add(HugeInteger&);
    ~HugeInteger();
    void output(); 
    HugeInteger subtract(HugeInteger&);
    bool isEqualTo(HugeInteger&);
    bool isNotEqualTo(HugeInteger&);
    bool isLessThan(HugeInteger&);
private:
    int *data;
    int length;
    bool sign;
};
#endif    
