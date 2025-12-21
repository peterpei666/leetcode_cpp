#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string>& strs)
    {
        bitset<100> ordered;
        int n = (int)strs.size();
        int m = (int)strs[0].size();
        int unordered = n - 1;
        int ans = 0;
        for (int c = 0; c < m && unordered > 0; c++)
        {
            bool f = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (!ordered[i] && strs[i][c] > strs[i + 1][c])
                {
                    f = true;
                    break;
                }
            }
            if (f)
            {
                ans++;
            }
            else
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if (!ordered[i] && strs[i][c] < strs[i + 1][c])
                    {
                        ordered[i] = true;
                        unordered--;
                    }
                }
            }
        }
        return ans;
    }
};
