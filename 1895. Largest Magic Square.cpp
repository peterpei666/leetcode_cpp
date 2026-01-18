#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestMagicSquare(vector<vector<int>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        unsigned int mat[51][51] = {0};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i + 1][j + 1] = grid[i][j] + mat[i + 1][j] + mat[i][j + 1] - mat[i][j];
            }
        }
        for (int sz = min(m, n); sz > 1; sz--)
        {
            for (int i = 0; i <= m - sz; i++)
            {
                for (int j = 0; j <= n - sz; j++)
                {
                    bool valid = true;
                    unsigned int temp = mat[i + 1][j + sz] + mat[i][j] - mat[i + 1][j] - mat[i][j + sz];
                    unsigned int d1 = 0, d2 = 0;
                    for (int k = 0; k < sz && valid; k++)
                    {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + sz - k - 1];
                        unsigned int rowSum = mat[i + k + 1][j + sz] - mat[i + k][j + sz] - mat[i + k + 1][j] + mat[i + k][j];
                        unsigned int colSum = mat[i + sz][j + k + 1] - mat[i][j + k + 1] - mat[i + sz][j + k] + mat[i][j + k];
                        if (temp != rowSum || temp != colSum)
                        {
                            valid = false;
                        }
                    }
                    if (d1 != temp || d2 != temp)
                    {
                        valid = false;
                    }
                    if (valid)
                    {
                        return sz;
                    }
                }
            }
        }
        return 1;
    }
};
