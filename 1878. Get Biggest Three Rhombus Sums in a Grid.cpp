#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<int>> pre1(m + 1, vector<int>(n + 2));
        vector<vector<int>> pre2(m + 1, vector<int>(n + 2));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pre1[i + 1][j + 1] = pre1[i][j] + grid[i][j];
                pre2[i + 1][j + 1] = pre2[i][j + 2] + grid[i][j];
            }
        }
        unordered_set<int> mp;
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!mp.count(grid[i][j]))
                {
                    pq.push(grid[i][j]);
                    mp.insert(grid[i][j]);
                    if (pq.size() > 3)
                    {
                        pq.pop();
                    }
                }
                for (int k = i + 2; k < m; k += 2)
                {
                    int x1 = (i + k) / 2, y1 = j - (k - i) / 2;
                    int x2 = (i + k) / 2, y2 = j + (k - i) / 2;
                    if (y1 < 0 || y2 >= n)
                    {
                        break;
                    }
                    int temp = pre2[x1 + 1][y1 + 1] - pre2[i][j + 2] + (pre1[x2 + 1][y2 + 1] - pre1[i][j]) + (pre1[k + 1][j + 1] - pre1[x1][y1]) + (pre2[k + 1][j + 1] - pre2[x2][y2 + 2]) - (grid[i][j] + grid[k][j] + grid[x1][y1] + grid[x2][y2]);
                    if (!mp.count(temp))
                    {
                        pq.push(temp);
                        mp.insert(temp);
                        if (pq.size() > 3)
                        {
                            pq.pop();
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
