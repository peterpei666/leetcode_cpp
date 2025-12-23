#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string>& strs)
    {
        int ans = 0;
        int n = (int)strs.size();
        int m = (int)strs[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (strs[j][i] < strs[j - 1][i])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
