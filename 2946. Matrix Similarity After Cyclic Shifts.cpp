#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool areSimilar(vector<vector<int>>& mat, int k)
    {
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        for (int i = 0; i < m; i++)
        {
            int temp[25];
            for (int j = 0; j < n; j++)
            {
                temp[((j - k) % n + n) % n] = mat[i][j];
            }
            if (memcmp(&mat[i][0], temp, sizeof(int) * n))
            {
                return false;
            }
        }
        return true;
    }
};
