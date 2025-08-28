#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
    {
        int n = (int)grid.size();
        int temp[10];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i + j < n; j++)
            {
                temp[j] = grid[i + j][j];
            }
            sort(&temp[0], &temp[0] + (n - i), greater<>());
            for (int j = 0; i + j < n; j++)
            {
                grid[i + j][j] = temp[j];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; i + j < n; j++)
            {
                temp[j] = grid[j][i + j];
            }
            sort(&temp[0], &temp[0] + (n - i));
            for (int j = 0; i + j < n; j++)
            {
                grid[j][i + j] = temp[j];
            }
        }
        return grid;
    }
};
