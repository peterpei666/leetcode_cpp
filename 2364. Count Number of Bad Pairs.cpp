#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int>& nums)
    {
        unordered_map<int, int> mp;
        long long count=0;
        int sz=(int)nums.size();
        for(int i=0;i<sz;i++)
        {
            mp[nums[i]-i]++;
        }
        for(auto it:mp)
        {
            count+=(long long)it.second*(long long)(sz-it.second);
        }
        return count/2;
    }
};
