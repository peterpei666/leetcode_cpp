#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int r = 0;
        int n = (int)gas.size();
        for (int i = 0; i < n; i++)
        {
            r += gas[i] - cost[i];
        }
        if (r < 0)
        {
            return -1;
        }
        int ans = 0;
        r = 0;
        for (int i = 0; i < n; i++)
        {
            r += gas[i] - cost[i];
            if (r < 0)
            {
                ans = i + 1;
                r = 0;
            }
        }
        return ans;
    }
};
