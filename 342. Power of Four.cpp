#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        while(n>1)
        {
            if(n&3)
            {
                return false;
            }
            n>>=2;
        }
        return n==1;
    }
};
