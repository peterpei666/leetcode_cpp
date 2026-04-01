#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, const string& directions)
    {
        int n = (int)positions.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });
        vector<int> stk;
        for (int i : ids)
        {
            if (directions[i] == 'R')
            {
                stk.push_back(i);
                continue;
            }
            while (!stk.empty() && directions[stk.back()] == 'R' && healths[i] > 0)
            {
                int top = stk.back();
                if (healths[top] == healths[i])
                {
                    healths[i] = 0;
                    healths[top] = 0;
                    stk.pop_back();
                }
                else if (healths[top] < healths[i])
                {
                    healths[top] = 0;
                    healths[i] -= 1;
                    stk.pop_back();
                }
                else
                {
                    healths[top] -= 1;
                    healths[i] = 0;
                }
            }
            if (healths[i] > 0)
            {
                stk.push_back(i);
            }
        }
        sort(stk.begin(), stk.end());
        vector<int> res;
        for (int i : stk)
        {
            res.push_back(healths[i]);
        }
        return res;
    }
};
