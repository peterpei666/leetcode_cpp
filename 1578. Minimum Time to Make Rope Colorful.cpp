#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCost(const string& colors, vector<int>& neededTime)
    {
        int n = (int)colors.size();
        int ans = 0;
        for (int i = 0; i < n;)
        {
            char c = colors[i];
            int sum = neededTime[i], t = neededTime[i];
            i++;
            while (i < n && colors[i] == c)
            {
                sum += neededTime[i];
                t = max(t, neededTime[i]);
                i++;
            }
            ans += sum - t;
        }
        return ans;
    }
};
