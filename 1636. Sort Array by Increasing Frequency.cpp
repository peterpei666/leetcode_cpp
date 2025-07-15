#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        int mp[201]={0};
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]+100]++;
        }
        sort(nums.begin(),nums.end(),[&](const int& a,const int& b) { return mp[a+100]==mp[b+100]?a>b:mp[a+100]<mp[b+100]; });
        return nums;
    }
};
