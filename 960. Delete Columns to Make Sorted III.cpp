#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string>& strs)
    {
        int dp[100];
        int n = (int)strs.size();
        int m = (int)strs[0].size();
        for (int i = 0; i < m; i++)
        {
            dp[i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < i; j++)
            {
                bool f = true;
                for (int k = 0; k < n; k++)
                {
                    if (strs[k][j] > strs[k][i])
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, dp[i]);
        }
        return m - ans;
    }
};
