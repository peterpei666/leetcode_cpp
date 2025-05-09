#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        int m=0;
        for(int i:nums)
        {
            m^=i;
        }
        m^=k;
        int count=0;
        while(m)
        {
            count+=m&1;
            m>>=1;
        }
        return count;
    }
};
