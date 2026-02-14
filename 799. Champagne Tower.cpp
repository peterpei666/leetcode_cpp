#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    double dp[2][101];
    
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        for (int i = 0; i <= 100; i++)
        {
            dp[0][i] = 0.0;
            dp[1][i] = 0.0;
        }
        dp[0][0] = poured;
        for (int i = 1; i <= query_row; i++)
        {
            dp[i & 1][0] = max(dp[(i - 1) & 1][0] - 1.0, 0.0) / 2;
            for (int j = 1; j <= query_row; j++)
            {
                dp[i & 1][j] = max(dp[(i - 1) & 1][j - 1] - 1.0, 0.0) / 2 + max(dp[(i - 1) & 1][j] - 1.0, 0.0) / 2;
            }
        }
        return min(1.0, dp[query_row & 1][query_glass]);
    }
};
