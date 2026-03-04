#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        int row[100] = {0};
        int col[100] = {0};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j])
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] && row[i] == 1 && col[j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
