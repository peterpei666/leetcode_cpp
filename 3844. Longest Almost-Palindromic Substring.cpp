#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int dp[2501][2501];
    string str;
    
    int find(int l, int r)
    {
        if (l >= r)
        {
            return 0;
        }
        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }
        if (str[l] == str[r])
        {
            dp[l][r] = find(l + 1, r - 1);
        }
        else
        {
            dp[l][r] = 1 + min(find(l + 1, r), find(l, r - 1));
        }
        return dp[l][r];
    }
    
public:
    int almostPalindromic(const string& s)
    {
        int n = (int)s.size();
        int ans = 1;
        str = s;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + ans; j < n; j++)
            {
                if (find(i, j) <= 1)
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
