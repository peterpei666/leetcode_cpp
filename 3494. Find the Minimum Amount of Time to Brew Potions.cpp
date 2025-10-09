#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minTime(vector<int>& skill, vector<int>& mana)
    {
        int m = (int)skill.size();
        int n = (int)mana.size();
        long long dp[5001];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[j + 1] = max(dp[j + 1], dp[j]) + 1LL * skill[j] * mana[i];
            }
            for (int j = m - 1; j >= 0; j--)
            {
                dp[j] = dp[j + 1] - 1LL * skill[j] * mana[i];
            }
        }
        return dp[m];
    }
};
