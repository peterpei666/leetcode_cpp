#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        sort(events.begin(), events.end());
        int dp[100000][2];
        int n = (int)events.size();
        memset(dp, -1, sizeof(dp));
        
        function<int(int, int)> dfs = [&](int idx, int cnt) -> int
        {
            if (cnt == 2 || idx >= n)
            {
                return 0;
            }
            if (dp[idx][cnt] == -1)
            {
                int end = events[idx][1];
                int l = idx + 1, r = n - 1;
                while (l < r)
                {
                    int mid = (r - l) / 2 + l;
                    if (events[mid][0] > end)
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                int include = events[idx][2] + (l < n && events[l][0] > end ? dfs(l, cnt + 1) : 0);
                int exclude = dfs(idx + 1, cnt);
                dp[idx][cnt] = max(include, exclude);
            }
            return dp[idx][cnt];
        };
        
        return dfs(0, 0);
    }
};
