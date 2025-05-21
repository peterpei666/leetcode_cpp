#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumPossibleSize(vector<int>& nums)
    {
        int prev=-1,count=0;
        for(int n:nums)
        {
            if(n>=prev)
            {
                prev=n;
                count++;
            }
        }
        return count;
    }
};
