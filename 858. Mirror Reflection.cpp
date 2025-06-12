#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        int g=gcd(p,q);
        p=(p/g)%2;
        q=(q/g)%2;
        if(p&&q)
        {
            return 1;
        }
        if(p)
        {
            return 0;
        }
        return 2;
    }
};
