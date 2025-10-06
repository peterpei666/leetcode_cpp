#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string crackSafe(int n, int k)
    {
        string start(n - 1, '0');
        unordered_set<string> memo;
        string ans;
        
        function<void(string)> dfs = [&](string node)
        {
            for (int i = 0; i < k; i++)
            {
                string edge = node + to_string(i);
                if (!memo.count(edge))
                {
                    memo.insert(edge);
                    dfs(edge.substr(1));
                    ans += to_string(i);
                }
            }
        };
        
        dfs(start);
        reverse(ans.begin(), ans.end());
        return start + ans;
    }
};
