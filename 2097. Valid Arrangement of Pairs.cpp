#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
private:
    void dfs(unordered_map<int, stack<int>>& mp, vector<vector<int>>& ans, int p)
    {
        stack<int>& stk = mp[p];
        while (!stk.empty())
        {
            int next = stk.top();
            stk.pop();
            dfs(mp, ans, next);
            ans.push_back({p, next});
        }
    }
    
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
    {
        unordered_map<int, int> in;
        unordered_map<int, int> out;
        unordered_map<int, stack<int>> mp;
        in.reserve(pairs.size());
        out.reserve(pairs.size());
        mp.reserve(pairs.size());
        for (auto& p : pairs)
        {
            in[p[1]]++;
            out[p[0]]++;
            mp[p[0]].push(p[1]);
        }
        int start = (*mp.begin()).first;
        for (auto& p : mp)
        {
            int i = p.first;
            if (out[i] == in[i] + 1)
            {
                start = i;
                break;
            }
        }
        vector<vector<int>> ans;
        dfs(mp, ans, start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
