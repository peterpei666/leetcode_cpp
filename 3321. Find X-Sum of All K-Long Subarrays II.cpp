#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x)
    {
        int n = (int)nums.size();
        vector<long long> ans(n - k + 1);
        unordered_map<int, int> cnt;
        set<pair<long long, int>, greater<>> top;
        set<pair<long long, int>, greater<>> bot;
        long long cur = 0;
        for (int i = 0; i < n; i++)
        {
            long long count = cnt[nums[i]];
            if (count)
            {
                if (bot.count({count, nums[i]}))
                {
                    bot.erase({count, nums[i]});
                }
                else
                {
                    top.erase({count, nums[i]});
                    cur -= count * nums[i];
                }
            }
            cnt[nums[i]]++;
            top.insert({count + 1, nums[i]});
            cur += (count + 1) * nums[i];
            if (top.size() > x)
            {
                auto it = prev(top.end());
                cur -= it->first * it->second;
                bot.insert({it->first, it->second});
                top.erase(it);
            }
            if (i >= k)
            {
                int count = cnt[nums[i - k]];
                if (bot.count({count, nums[i - k]}))
                {
                    bot.erase({count, nums[i - k]});
                }
                else
                {
                    auto it = top.find({count, nums[i - k]});
                    cur -= it->first * it->second;
                    top.erase(it);
                }
                if (count > 1)
                {
                    bot.insert({count - 1, nums[i - k]});
                }
                cnt[nums[i - k]]--;
                if (top.size() < x && !bot.empty())
                {
                    auto it = bot.begin();
                    cur += it->first * it->second;
                    top.insert({it->first, it->second});
                    bot.erase(it);
                }
            }
            if (i + 1 >= k)
            {
                ans[i + 1 - k] = cur;
            }
        }
        return ans;
    }
};
