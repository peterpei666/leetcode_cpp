#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minStickers(vector<string>& stickers, string target)
    {
        int n = (int)stickers.size();
        int freq[50][26];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++)
        {
            for (char c : stickers[i])
            {
                freq[i][c - 'a']++;
            }
        }
        unordered_map<string, int> memo;
        memo[""] = 0;
        
        function<int(string)> dfs = [&](string cur) -> int
        {
            if (memo.count(cur))
            {
                return memo[cur];
            }
            int need[26] = {0};
            for (char c : cur)
            {
                need[c - 'a']++;
            }
            int res = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (freq[i][cur[0] - 'a'] == 0)
                {
                    continue;
                }
                string next;
                for (int j = 0; j < 26; j++)
                {
                    if (need[j] > 0)
                    {
                        int remain = max(0, need[j] - freq[i][j]);
                        next.append(remain, 'a' + j);
                    }
                }
                int sub = dfs(next);
                if (sub != -1)
                {
                    res = min(res, sub + 1);
                }
            }
            memo[cur] = (res == INT_MAX ? -1 : res);
            return memo[cur];
        };
        
        sort(target.begin(), target.end());
        return dfs(target);
    }
};
