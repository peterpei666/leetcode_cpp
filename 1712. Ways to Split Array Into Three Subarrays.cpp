#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int waysToSplit(vector<int>& nums)
    {
        const int mod=1e9+7;
        int n=(int)nums.size();
        vector<long long> prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        int cnt=0;
        for(int i=1;i<n-1;i++)
        {
            int l=(int)(lower_bound(prefix.begin(),prefix.end()-1,2*prefix[i])-prefix.begin());
            int r=(int)(upper_bound(prefix.begin(),prefix.end()-1,(prefix[n]+prefix[i])/2)-prefix.begin()-1);
            if(r>=l)
            {
                cnt+=r-l+1;
                cnt%=mod;
            }
        }
        return cnt;
    }
};
