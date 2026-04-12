#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    inline int dis(int a, int b)
    {
        return abs(a % 6 - b % 6) + abs(a / 6 - b / 6);
    }
    
public:
    int minimumDistance(const string& word)
    {
        int n = (int)word.size();
        int dp[2][26][26] = {0};
        for (int i = 0; i < n; i++)
        {
            int mask = i & 1;
            int next = mask ^ 1;
            int t = word[i] - 'A';
            memset(dp[next], 0x7f, sizeof(dp[0]));
            for (int a = 0; a < 26; a++)
            {
                for (int b = 0; b < 26; b++)
                {
                    dp[next][a][t] = min(dp[next][a][t], dp[mask][a][b] + dis(b, t));
                    dp[next][t][b] = min(dp[next][t][b], dp[mask][a][b] + dis(a, t));
                }
            }
        }
        int ans = INT_MAX;
        int mask = n & 1;
        for (int a = 0; a < 26; a++)
        {
            for (int b = 0; b < 26; b++)
            {
                ans = min(ans, dp[mask][a][b]);
            }
        }
        return ans;
    }
};
