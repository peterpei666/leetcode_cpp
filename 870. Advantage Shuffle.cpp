#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2)
    {
        multiset<int> list(nums1.begin(),nums1.end());
        int n=(int)nums1.size();
        vector<int> ret(n);
        vector<pair<int,int>> nums(n);
        for(int i=0;i<n;i++)
        {
            nums[i]={nums2[i],i};
        }
        sort(nums.begin(),nums.end());
        for(auto& [x,idx]:nums)
        {
            auto it=list.upper_bound(x);
            if(it==list.end())
            {
                it=list.begin();
            }
            ret[idx]=*it;
            list.erase(it);
        }
        return ret;
    }
};
