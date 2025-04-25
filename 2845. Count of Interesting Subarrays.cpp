#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k)
    {
        int prefix=0;
        long long ret=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefix+=(nums[i]%modulo==k);
            ret+=mp[(prefix-k+modulo)%modulo];
            mp[prefix%modulo]++;
        }
        return ret;
    }
};
