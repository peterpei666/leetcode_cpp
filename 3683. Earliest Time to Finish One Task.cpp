#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int earliestTime(vector<vector<int>>& tasks)
    {
        int n = (int)tasks.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, tasks[i][0] + tasks[i][1]);
        }
        return ans;
    }
};
