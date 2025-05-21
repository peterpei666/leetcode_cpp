#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int>& nums)
    {
        int m=*max_element(nums.begin(),nums.end());
        int cur=0,longest=0;
        for(int i:nums)
        {
            if(i==m)
            {
                cur++;
                longest=max(longest,cur);
            }
            else
            {
                cur=0;
            }
        }
        return longest;
    }
};
