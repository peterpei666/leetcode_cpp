#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        int n = (int)spells.size();
        int m = (int)potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            long long target;
            if (success % spells[i])
            {
                target = success / spells[i] + 1;
            }
            else
            {
                target = success / spells[i];
            }
            if (target > potions[m - 1])
            {
                ans[i] = 0;
                continue;
            }
            ans[i] = m - (int)(lower_bound(potions.begin(), potions.end(), target) - potions.begin());
        }
        return ans;
    }
};
