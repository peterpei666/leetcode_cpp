#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    string simplify(const string& s)
    {
        string ans = "";
        ans.push_back(s[0]);
        int n = (int)s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                ans += s[i];
            }
        }
        return ans;
    }
    
public:
    int strangePrinter(const string& ori)
    {
        string s = simplify(ori);
        int n = (int)s.size();
        int memo[n][n];
        memset(memo, -1,sizeof(memo));
        
        function<int(int, int)> dfs = [&](int l, int r) -> int
        {
            if (l > r)
            {
                return 0;
            }
            if (memo[l][r] != -1)
            {
                return memo[l][r];
            }
            int ans = 1 + dfs(l + 1, r);
            for (int i = l + 1; i <= r; i++)
            {
                if (s[l] == s[i])
                {
                    ans = min(ans, dfs(l, i - 1) + dfs(i + 1, r));
                }
            }
            memo[l][r] = ans;
            return ans;
        };
        
        return dfs(0, n - 1);
    }
};
