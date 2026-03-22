#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        bool flag[4] = {true, true, true, true};
        int n = (int)mat.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[i][j])
                {
                    flag[0]=false;
                }
                if (mat[i][j] != target[j][n - i - 1])
                {
                    flag[1]=false;
                }
                if (mat[i][j] != target[n - i - 1][n - j - 1])
                {
                    flag[2]=false;
                }
                if (mat[i][j] != target[n - j - 1][i])
                {
                    flag[3]=false;
                }
            }
        }
        return flag[0] | flag[1] | flag[2] | flag[3];
    }
};
