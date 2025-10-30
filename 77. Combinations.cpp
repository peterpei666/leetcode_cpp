#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp(k);
        vector<vector<int>> ans;
        
        function<void(int, int)> dfs = [&](int idx, int t)
        {
            if (t == k)
            {
                ans.push_back(temp);
                return;
            }
            if (n - idx + 1 < k - t)
            {
                return;
            }
            temp[t] = idx;
            dfs(idx + 1, t + 1);
            dfs(idx + 1, t);
        };
        
        dfs(1, 0);
        return ans;
    }
};
