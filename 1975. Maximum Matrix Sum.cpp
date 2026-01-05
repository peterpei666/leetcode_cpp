#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int n = (int)matrix.size();
        long long ans = 0;
        int neg = 0;
        int minAbs = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < 0)
                {
                    ans -= matrix[i][j];
                    neg++;
                    minAbs = min(minAbs, -matrix[i][j]);
                }
                else
                {
                    ans += matrix[i][j];
                    minAbs = min(minAbs, matrix[i][j]);
                }
            }
        }
        if (neg % 2)
        {
            return ans - 2 * minAbs;
        }
        return ans;
    }
};
