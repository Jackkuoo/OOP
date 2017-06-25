#include <iostream>
#include <string>
#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger()
{
    data = new int[40];
    length = 0;
    sign = true;
}
HugeInteger::HugeInteger(long a)
{
    data = new int[40];
    int idx;
    for (idx = 0;a > 0;idx++)
    {
        data[idx] = a % 10;
        a /= 10;
    }
    length = idx;
    sign = true;
}
HugeInteger::HugeInteger(string a)
{
    data = new int[40];
    length = a.length();
    for (int idx = 0;idx < length;idx++)
        data[idx] = a[length-1-idx] - 48;
    sign = true;
}
HugeInteger::HugeInteger(int a)
{
    data = new int[40];
    int idx;
    for (idx = 0;a > 0;idx++)
    {
        data[idx] = a % 10;
        a /= 10;
    }
    length = idx;
    sign = true;
}
HugeInteger::HugeInteger(HugeInteger &a)
{
    data = new int[40];
    for (int idx = 0;idx < a.length;idx++)
        data[idx] = a.data[idx];
    length = a.length;
    sign = a.sign;
}
HugeInteger::~HugeInteger() {}
void HugeInteger::output()
{
    if (sign == false)
        cout << "-";
    for (int idx = length-1;idx >= 0;idx--)
        cout << data[idx];
}
HugeInteger HugeInteger::add(HugeInteger &b)
{
    HugeInteger a;
    int carry = 0;
    int idx;
    for (idx = 0;idx < length || idx < b.length;idx++)
    {
        a.data[idx] = (data[idx] + b.data[idx] + carry) % 10;
        if (data[idx] + b.data[idx] + carry >= 10)
            carry = 1;
        else 
            carry = 0;
    }
    if (carry == 1)
    {
        a.data[idx] = 1;
        idx++;
    }
    a.length = idx;
    return a;
}
HugeInteger HugeInteger::subtract(HugeInteger &b)
{
    HugeInteger a;
    int lend = 0;
    int idx;
    for (idx = 0;idx < length || idx < b.length;idx++)
    {
        a.data[idx] = (data[idx] - b.data[idx] - lend + 10) % 10;
        if (data[idx] - b.data[idx] - lend < 0)
            lend = 1;
        else 
            lend = 0;
    }
    if (a.data[idx-1] == 0)
    {
        idx--;
    }
    a.length = idx;
    return a;
}
bool HugeInteger::isEqualTo(HugeInteger &b)
{
    if (length != b.length)
        return false;
    for (int idx = 0;idx < length && idx < b.length;idx++)
    {
        if (data[idx] != b.data[idx])
            return false;
    }
    return true; 
}
bool HugeInteger::isNotEqualTo(HugeInteger &b)
{
    if (length != b.length)
        return true;
    for (int idx = 0;idx < length && idx < b.length;idx++)
    {
        if (data[idx] != b.data[idx])
            return true;
    }
    return false; 
}
bool HugeInteger::isLessThan(HugeInteger &b)
{
    if (length > b.length)
        return false;
    else if (length < b.length)
        return true;
    else
    {
        for (int idx = length-1;idx >= 0;idx--)
        {
            if (data[idx] < b.data[idx])
                return true;
            else if (data[idx] > b.data[idx])
                return false;
            else
                continue;
        }
        return false;
    }
}
