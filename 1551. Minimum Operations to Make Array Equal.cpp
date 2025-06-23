#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(int n)
    {
        int sum=0;
        for(int i=n-1;i>0;i-=2)
        {
            sum+=i;
        }
        return sum;
    }
};
