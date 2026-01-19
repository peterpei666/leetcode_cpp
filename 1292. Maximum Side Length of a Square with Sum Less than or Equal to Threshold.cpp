#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold)
    {
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        int pre[m + 1][n + 1];
        memset(pre, 0, sizeof(pre));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + mat[i][j];
            }
        }
        int l = 1, r = min(m, n);
        int ans = 0;
        while (l <= r)
        {
            bool valid = false;
            int mid = (l + r + 1) / 2;
            for (int i = 1; i + mid - 1 <= m && !valid; i++)
            {
                for (int j = 1; j + mid - 1 <= n && !valid; j++)
                {
                    if (pre[i + mid - 1][j + mid - 1] - pre[i + mid - 1][j - 1] - pre[i - 1][j + mid - 1] + pre[i - 1][j - 1] <= threshold)
                    {
                        valid = true;
                    }
                }
            }
            if (valid)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
