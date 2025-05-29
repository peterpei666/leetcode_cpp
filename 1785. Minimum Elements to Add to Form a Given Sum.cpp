#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minElements(vector<int>& nums, int limit, int goal)
    {
        long long sum=0;
        for(int i:nums)
        {
            sum+=i;
        }
        sum=abs(sum-goal);
        int n=(int)(sum/limit);
        if(sum%limit)
        {
            n++;
        }
        return n;
    }
};
