#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int n1=1,n2=0;
        while(n)
        {
            n1*=n%10;
            n2+=n%10;
            n/=10;
        }
        return n1-n2;
    }
};
