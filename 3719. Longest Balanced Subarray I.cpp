#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int longestBalanced(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 0;
        for (int l = 0; l < n; l++)
        {
            bitset<100001> mp;
            int odd_cnt = 0;
            int even_cnt = 0;
            for (int r = l; r < n; r++)
            {
                if (nums[r] & 1)
                {
                    if (!mp.test(nums[r]))
                    {
                        odd_cnt++;
                        mp.set(nums[r]);
                    }
                }
                else
                {
                    if (!mp.test(nums[r]))
                    {
                        even_cnt++;
                        mp.set(nums[r]);
                    }
                }
                if (odd_cnt == even_cnt)
                {
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans;
    }
};
