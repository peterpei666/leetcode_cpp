#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumOR(vector<vector<int>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int ans = 0;
        for (int b = 29; b >= 0; b--)
        {
            int temp = ans | ((1 << b) - 1);
            bool p = true;
            for (int i = 0; i < m; i++)
            {
                bool valid = false;
                for (int j = 0; j < n; j++)
                {
                    if ((grid[i][j] | temp) == temp)
                    {
                        valid = true;
                        break;
                    }
                }
                if (!valid)
                {
                    p = false;
                    break;
                }
            }
            if (!p)
            {
                ans |= 1 << b;
            }
        }
        return ans;
    }
};
