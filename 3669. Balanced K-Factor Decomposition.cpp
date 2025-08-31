#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> minDifference(int n, int k)
    {
        vector<int> temp;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                temp.push_back(i);
            }
        }
        int sz = (int)temp.size();
        vector<int> ans;
        vector<int> path(k);
        
        function<void(int, int, int)> dfs = [&](int idx, int m, int prod)
        {
            if (idx == k)
            {
                if ((ans.empty() || path > ans) && prod == n)
                {
                    ans = path;
                }
                return;
            }
            for (int i = m; i < sz; i++)
            {
                if ((n / prod) % temp[i])
                {
                    continue;;
                }
                path[idx] = temp[i];
                dfs(idx + 1, i, prod * temp[i]);
            }
        };
        
        dfs(0, 0, 1);
        return ans;
    }
};
