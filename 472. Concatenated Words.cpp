#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
    {
        unordered_set<string> mp(words.begin(), words.end());
        vector<string> ans;
        int dp[40];
        
        function<bool(const string&, int, int)> dfs =
            [&](const string& s, int idx, int cnt) -> bool
        {
            if (idx == s.size())
            {
                return cnt > 1;
            }
            if (dp[idx] != -1)
            {
                return dp[idx];
            }
            string temp;
            for (int i = idx; i < s.size(); i++)
            {
                temp.push_back(s[i]);
                if (mp.count(temp))
                {
                    if (dfs(s, i + 1, cnt + 1))
                    {
                        return dp[idx] = 1;
                    }
                }
            }
            return dp[idx] = 0;
        };

        for (auto& w : words)
        {
            memset(dp, -1, sizeof(dp));
            if (dfs(w, 0, 0))
            {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
