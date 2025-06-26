#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int>& nums, int p)
    {
        int sum=0;
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]%=p;
            sum=(sum+nums[i])%p;
        }
        if(sum==0)
        {
            return 0;
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        int cur=0,ans=n;
        for(int i=0;i<n;i++)
        {
            cur=(cur+nums[i])%p;
            int temp=(cur-sum+p)%p;
            if(mp.count(temp))
            {
                ans=min(ans,i-mp[temp]);
            }
            mp[cur]=i;
        }
        return ans==n?-1:ans;
    }
};
