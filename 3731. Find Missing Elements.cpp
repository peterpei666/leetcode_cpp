#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int>& nums)
    {
        bitset<101> mp;
        int l = 101, r = 0;
        for (int i : nums)
        {
            l = min(l, i);
            r = max(r, i);
            mp.set(i);
        }
        vector<int> ans;
        for (int i = l; i <= r; i++)
        {
            if (!mp.test(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
