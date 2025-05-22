#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        long long i=1;
        long long base=9;
        while(n>i*base)
        {
            n-=i*base;
            i++;
            base*=10;
        }
        long long num=pow(10,i-1)+(n-1)/i;
        string s=to_string(num);
        return s[(n-1)%i]-'0';
    }
};
