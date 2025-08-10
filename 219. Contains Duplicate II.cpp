#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_set<int> find;
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            if(find.count(nums[i]))
            {
                return true;
            }
            find.insert(nums[i]);
            if(i-k>=0)
            {
                find.erase(nums[i-k]);
            }
        }
        return false;
    }
};
