#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    string make_range(int l, int r)
    {
        return l == r ? to_string(l) : to_string(l) + "->" + to_string(r);
    }
    
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int n = (int)nums.size();
        if (n == 0)
        {
            return {};
        }
        int l = nums[0], r = nums[0];
        vector<string> ans;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != r + 1)
            {
                ans.push_back(make_range(l, r));
                l = nums[i];
                r = nums[i];
            }
            else
            {
                r++;
            }
        }
        ans.push_back(make_range(l, r));
        return ans;
    }
};
