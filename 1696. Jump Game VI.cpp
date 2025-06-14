#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class Solution
{
public:
    int maxResult(vector<int>& nums, int k)
    {
        deque<int> dq;
        int n=(int)nums.size();
        vector<int> dp(n);
        dq.push_back(0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            while(dq.front()<i-k)
            {
                dq.pop_front();
            }
            dp[i]=nums[i]+dp[dq.front()];
            while(!dq.empty()&&dp[dq.back()]<=dp[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp.back();
    }
};
