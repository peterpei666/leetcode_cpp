#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    long long maximumTotalDamage(vector<int>& power)
    {
        map<int, int> mp;
        for (int p : power)
        {
            mp[p]++;
        }
        vector<pair<int, int>> vec = {{INT_MIN, 0}};
        for (auto& p : mp)
        {
            vec.push_back(p);
        }
        int n = (int)vec.size();
        vector<long long> dp(n, 0);
        long long temp = 0;
        for (int i = 1, j = 1; i < n; i++)
        {
            while (j < i && vec[j].first < vec[i].first - 2)
            {
                temp = max(temp, dp[j]);
                j++;
            }
            dp[i] = temp + 1LL * vec[i].first * vec[i].second;
        }
        long long ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
