#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int minExtraChar(const string& s, vector<string>& dictionary)
    {
        unordered_set<string> mp(dictionary.begin(), dictionary.end());
        int dp[51];
        for (int i = 0; i < 51; i++)
        {
            dp[i] = i;
        }
        int n = (int)s.size();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (mp.count(s.substr(j, i - j)))
                {
                    dp[i] = min(dp[i], dp[j]);
                    for (int k = i + 1; k <= n; k++)
                    {
                        dp[k] = min(dp[k], dp[k - 1] + 1);
                    }
                }
            }
        }
        return dp[n];
    }
};
