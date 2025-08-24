#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int>& nums)
    {
        int prev=-1,temp=0;
        int ans=0;
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            while(i<n&&nums[i]==1)
            {
                temp++;
                i++;
            }
            ans=max(ans,prev+temp);
            if(i<n&&nums[i]==0)
            {
                if(temp==0)
                {
                    prev=0;
                }
                else
                {
                    prev=temp;
                    temp=0;
                }
            }
        }
        return ans;
    }
};
