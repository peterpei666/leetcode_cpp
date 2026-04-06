#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        unordered_set<long long> mp;
        for (auto& p : obstacles)
        {
            mp.insert(p[0] * (1LL << 32) + p[1]);
        }
        int d = 0;
        int x = 0, y = 0;
        int ans = 0;
        for (int cmd : commands)
        {
            if (cmd == -2)
            {
                d = (d + 3) & 3;
            }
            else if (cmd == -1)
            {
                d = (d + 1) & 3;
            }
            else
            {
                for (int i = 0; i < cmd; i++)
                {
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];
                    if (!mp.count(nx * (1LL << 32) + ny))
                    {
                        x = nx;
                        y = ny;
                        ans = max(ans, x * x + y * y);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
