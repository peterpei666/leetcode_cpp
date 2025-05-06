#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if(n<=0)
        {
            return false;
        }
        while(n&&(n&1)==0)
        {
            n>>=1;
        }
        if(n==1)
        {
            return true;
        }
        return false;
    }
};
