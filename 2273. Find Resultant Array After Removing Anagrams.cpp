#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string>& words)
    {
        vector<string> ans;
        ans.push_back(words[0]);
        int n = (int)words.size();
        int pre[26] = {0};
        int cur[26] = {0};
        for (int i = 0; i < words[0].size(); i++)
        {
            pre[words[0][i] - 'a']++;
        }
        for (int i = 1; i < n; i++)
        {
            int m = (int)words[i].size();
            for (int j = 0; j < m; j++)
            {
                cur[words[i][j] - 'a']++;
            }
            if (memcmp(pre, cur, sizeof(pre)))
            {
                ans.push_back(words[i]);
                memcpy(pre, cur, sizeof(pre));
            }
            memset(cur, 0, sizeof(cur));
        }
        return ans;
    }
};
