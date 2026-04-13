#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestBalanced(const string& s)
    {
        int n = (int)s.size();
        unordered_map<int, vector<int>> mp;
        mp[0].push_back(-1);
        int cur = 0;
        int ans = 0;
        int cnt0 = 0;
        for (int i = 0; i < n; i++)
        {
            cnt0 += s[i] == '0';
        }
        int cnt1 = n - cnt0;
        for (int i = 0; i < n; i++)
        {
            cur += (s[i] == '1' ? 1 : -1);
            for (int k : {cur - 2, cur, cur + 2})
            {
                if (!mp.count(k))
                {
                    continue;
                }
                for (int l : mp[k])
                {
                    int sz = i - l;
                    int dif = cur - k;
                    int c1 = (sz + dif) / 2;
                    int c0 = sz - c1;
                    if (dif == 0 || (dif == 2 && cnt0 > c0) || (dif == -2 && cnt1 > c1))
                    {
                        ans = max(ans, sz);
                        break;
                    }
                }
            }
            if (mp[cur].size() < 2)
            {
                mp[cur].push_back(i);
            }
        }
        return ans;
    }
};
