#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int countDistinct(vector<int>& nums, int k, int p)
    {
        unordered_set<string> mp;
        int pre[201] = {0};
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + (nums[i] % p == 0);
        }
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = i; j < n && pre[j + 1] - pre[i] <= k; j++)
            {
                s += nums[j];
                s += '#';
                mp.insert(s);
            }
        }
        return (int)mp.size();
    }
};
