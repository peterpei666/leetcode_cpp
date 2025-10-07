#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        int n = (int)rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full;
        vector<int> dry;
        for (int i = 0; i < n; i++)
        {
            if (rains[i] == 0)
            {
                dry.push_back(i);
            }
            else
            {
                ans[i] = -1;
                if (full.count(rains[i]))
                {
                    auto it = upper_bound(dry.begin(), dry.end(), full[rains[i]]);
                    if (it == dry.end())
                    {
                        return {};
                    }
                    ans[*it] = rains[i];
                    dry.erase(it);
                }
                full[rains[i]] =i;
            }
        }
        return ans;
    }
};
