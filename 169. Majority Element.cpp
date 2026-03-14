#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> cnt;
        for (int i : nums)
        {
            cnt[i]++;
        }
        for (auto [x, n] : cnt)
        {
            if (n > nums.size() / 2)
            {
                return x;
            }
        }
        return -1;
    }
};
