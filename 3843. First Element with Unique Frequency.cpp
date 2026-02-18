#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstUniqueFreq(vector<int>& nums)
    {
        int n = (int)nums.size();
        int freq[100001] = {0};
        int cnt[100001] = {0};
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        for (int i = 1; i < 100001; i++)
        {
            cnt[freq[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (cnt[freq[nums[i]]] == 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};
