#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ret=0;
        for(int i=0;right;right>>=1,left>>=1,i++)
        {
            if((right&1)&&right-1<left)
            {
                ret+=(1<<i);
            }
        }
        return ret;
    }
};
