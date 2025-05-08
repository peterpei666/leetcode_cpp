#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long res=x;
        long long p=1;
        n--;
        while(n)
        {
            if((x&p)==0)
            {
                res|=(n&1)*p;
                n>>=1;
            }
            p<<=1;
        }
        return res;
    }
};
