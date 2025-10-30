#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int l = 0, r = m - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (matrix[mid][0] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        int k = l;
        l = 0;
        r = n - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (matrix[k][mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        return matrix[k][l] == target;
    }
};
