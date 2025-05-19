#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int n=0,p=0;
        int mask=0;
        while(num2)
        {
            if(num2&1)
            {
                n++;
            }
            num2>>=1;
        }
        while(num1>(1<<p))
        {
            p++;
        }
        while(p&&n)
        {
            if(num1&(1<<p))
            {
                n--;
                mask|=1<<p;
            }
            p--;
        }
        for(p=0;n;p++)
        {
            if(!(mask&(1<<p)))
            {
                n--;
                mask|=1<<p;
            }
        }
        return mask;
    }
};
