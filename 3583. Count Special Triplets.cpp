#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int specialTriplets(vector<int>& nums)
    {
        unordered_map<int,vector<int>> list;
        const int mod=1e9+7;
        for(int i=0;i<nums.size();i++)
        {
            list[nums[i]].push_back(i);
        }
        long long cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i];
            if(list.count(temp)==false)
            {
                continue;
            }
            int m=(int)(list[temp*2].end()-upper_bound(list[temp*2].begin(),list[temp*2].end(),i));
            int n=(int)(lower_bound(list[temp*2].begin(),list[temp*2].end(),i)-list[temp*2].begin());
            cnt+=(long long)m*n;
            cnt%=mod;
        }
        return (int)cnt;
    }
};
