#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int clumsy(int n)
    {
        int ans[8]={1,2,2,-1,0,0,3,3};
        if(n>4)
        {
            return n+ans[n%4];
        }
        else
        {
            return n+ans[n+3];
        }
    }
};
