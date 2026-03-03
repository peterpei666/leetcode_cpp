#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countElements(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j + 1 < n && nums[j + 1] == nums[i])
            {
                j++;
            }
            if (n - j - 1 >= k)
            {
                ans += j - i + 1;
            }
            i = j;
        }
        return ans;
    }
};
