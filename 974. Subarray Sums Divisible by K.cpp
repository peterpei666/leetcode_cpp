#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int mp[k];
        memset(mp,0,sizeof(mp));
        mp[0]=1;
        int cur=0;
        int ans=0;
        for(int i:nums)
        {
            cur=((cur+i)%k+k)%k;
            ans+=mp[cur];
            mp[cur]++;
        }
        return ans;
    }
};
