#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls)
    {
        int n = (int)robots.size();
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = {robots[i], distance[i]};
        }
        sort(temp.begin(), temp.end());
        sort(walls.begin(), walls.end());
        int dp[2][2];
        
        function<int(int, int)> count = [&](int l, int r) -> int
        {
            if (l > r)
            {
                return 0;
            }
            auto it1 = lower_bound(walls.begin(), walls.end(), l);
            auto it2 = upper_bound(walls.begin(), walls.end(), r);
            return (int)(it2 - it1);
        };
        
        dp[0][0] = count(temp[0].first - temp[0].second, temp[0].first);
        dp[0][1] = count(temp[0].first, min(temp[0].first + temp[0].second, n > 1 ? temp[1].first - 1 : INT_MAX));
        for (int i = 1; i < n - 1; i++)
        {
            int res0 = 0;
            res0 = max(res0, dp[(i - 1) % 2][0] + count(max(temp[i - 1].first + 1, temp[i].first - temp[i].second), temp[i].first));
            res0 = max(res0, dp[(i - 1) % 2][1] + count(max(temp[i - 1].first + temp[i - 1].second + 1, temp[i].first - temp[i].second), temp[i].first));
            dp[i % 2][0] = res0;
            int res1 = 0;
            res1 = max(res1, dp[(i - 1) % 2][0] + count(temp[i].first, min(temp[i].first + temp[i].second, temp[i + 1].first - 1)));
            res1 = max(res1, dp[(i - 1) % 2][1] + count(temp[i].first, min(temp[i].first + temp[i].second, temp[i + 1].first - 1)));
            dp[i % 2][1] = res1;
        }
        if (n > 1)
        {
            int res0 = 0;
            res0 = max(res0, dp[(n - 2) % 2][0] + count(max(temp[n - 2].first + 1, temp[n - 1].first - temp[n - 1].second), temp[n - 1].first));
            res0 = max(res0, dp[(n - 2) % 2][1] + count(max(temp[n - 2].first + temp[n - 2].second + 1, temp[n - 1].first - temp[n - 1].second), temp[n - 1].first));
            dp[(n - 1) % 2][0] = res0;
            int res1 = 0;
            res1 = max(res1, dp[(n - 2) % 2][0] + count(temp[n - 1].first, temp[n - 1].first + temp[n - 1].second));
            res1 = max(res1, dp[(n - 2) % 2][1] + count(temp[n - 1].first, temp[n - 1].first + temp[n - 1].second));
            dp[(n - 1) % 2][1] = res1;
        }
        return max(dp[(n - 1) % 2][0], dp[(n - 1) % 2][1]);
    }
};
