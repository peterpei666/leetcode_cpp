#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings)
    {
        int x1[100001];
        int x2[100001] = {0};
        int y1[100001];
        int y2[100001] = {0};
        memset(x1, 0x7f, sizeof(x1));
        memset(y1, 0x7f, sizeof(y1));
        int m = (int)buildings.size();
        for (int i = 0; i < m; i++)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];
            if (x < x1[y])
            {
                x1[y] = x;
            }
            if (x > x2[y])
            {
                x2[y] = x;
            }
            if (y < y1[x])
            {
                y1[x] = y;
            }
            if (y > y2[x])
            {
                y2[x] = y;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];
            if (x > x1[y] && x < x2[y] && y > y1[x] && y < y2[x])
            {
                ans++;
            }
        }
        return ans;
    }
};
