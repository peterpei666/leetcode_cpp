#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int rev(int x)
    {
        int ret=0;
        while(x)
        {
            ret*=10;
            ret+=x%10;
            x/=10;
        }
        return ret;
    }
    
    int countNicePairs(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        for(int i:nums)
        {
            mp[i-rev(i)]++;
        }
        const int MOD=1e9+7;
        long long count=0;
        for(auto& [i,n]:mp)
        {
            count+=((long long)n)*(n-1)/2;
        }
        return count%MOD;
    }
};
