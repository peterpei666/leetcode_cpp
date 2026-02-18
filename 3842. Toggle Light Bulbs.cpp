#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs)
    {
        int n = (int)bulbs.size();
        bitset<101> mp;
        for (int i = 0; i < n; i++)
        {
            mp.flip(bulbs[i]);
        }
        vector<int> ans;
        for (int i = 1; i <= 100; i++)
        {
            if (mp.test(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
