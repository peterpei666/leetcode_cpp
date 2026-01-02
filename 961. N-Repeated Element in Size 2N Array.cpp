#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int>& nums)
    {
        int n = (int)nums.size();
        int cnt[10001] = {0};
        for (int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }
        for (int i = 0; i < 10001; i++)
        {
            if (cnt[i] == n / 2)
            {
                return i;
            }
        }
        return -1;
    }
};
