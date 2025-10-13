#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int sumDivisibleByK(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        int cnt[101] = {0};
        for (int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (cnt[i] && cnt[i] % k == 0)
            {
                ans += i * cnt[i];
            }
        }
        return ans;
    }
};
