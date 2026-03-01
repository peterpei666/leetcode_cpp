#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int>& nums, int k, int m)
    {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int unique1 = 0;
        int unique2 = 0;
        int valid = 0;
        int n = (int)nums.size();
        int l1 = 0, l2 = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            mp1[nums[i]]++;
            if (mp1[nums[i]] == 1)
            {
                unique1++;
            }
            while (unique1 > k)
            {
                mp1[nums[l1]]--;
                if (mp1[nums[l1]] == 0)
                {
                    unique1--;
                }
                l1++;
            }
            mp2[nums[i]]++;
            if (mp2[nums[i]] == 1)
            {
                unique2++;
            }
            if (mp2[nums[i]] == m)
            {
                valid++;
            }
            while (l2 <= i)
            {
                if (mp2[nums[l2]] > m)
                {
                    mp2[nums[l2]]--;
                    l2++;
                }
                else if (unique2 > k)
                {
                    if (mp2[nums[l2]] == m)
                    {
                        valid--;
                    }
                    mp2[nums[l2]]--;
                    if (mp2[nums[l2]] == 0)
                    {
                        unique2--;
                    }
                    l2++;
                }
                else
                {
                    break;
                }
            }
            if (unique1 == k && unique2 == k && valid == k)
            {
                ans += l2 - l1 + 1;
            }
        }
        return ans;
    }
};
