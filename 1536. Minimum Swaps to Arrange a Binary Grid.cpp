#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<vector<int>>& grid)
    {
        int n = (int)grid.size();
        int arr[200];
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            while (j < n && grid[i][n - 1 - j] == 0)
            {
                j++;
            }
            arr[i] = j;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < n - i - 1)
            {
                int p = -1;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] >= n - i - 1)
                    {
                        p = j;
                        break;
                    }
                }
                if (p == -1)
                {
                    return -1;
                }
                for (int k = p; k > i; k--)
                {
                    swap(arr[k], arr[k - 1]);
                    ans++;
                }
            }
        }
        return ans;
    }
};
