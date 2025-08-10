#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
    {
        set<int> mp;
        int n=(int)nums.size();
        int dif=INT_MAX;
        for(int i=0;i<n;i++)
        {
            auto it=mp.lower_bound(nums[i]);
            if(it!=mp.end())
            {
                dif=min(dif,abs(*it-nums[i]));
            }
            if(it!=mp.begin())
            {
                it--;
                dif=min(dif,abs(*it-nums[i]));
            }
            if(dif<=valueDiff)
            {
                return true;
            }
            if(mp.size()>=indexDiff)
            {
                mp.erase(nums[i-indexDiff]);
            }
            mp.insert(nums[i]);
        }
        return false;
    }
};
