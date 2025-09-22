#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        int n = (int)nums.size();
        int cnt[101] = {0};
        for (int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }
        int ans = 0, temp = 0;
        for (int i = 0; i < 101; i++)
        {
            if (cnt[i] > temp)
            {
                ans = 0;
                temp = cnt[i];
            }
            if (cnt[i] == temp)
            {
                ans += temp;
            }
        }
        return ans;
    }
};
