#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool isInterleave(const string& s1, const string& s2, const string& s3)
    {
        int cnt[26] = {0};
        for (char c : s1)
        {
            cnt[c - 'a']++;
        }
        for (char c : s2)
        {
            cnt[c - 'a']++;
        }
        for (char c : s3)
        {
            cnt[c - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] != 0)
            {
                return false;
            }
        }
        int n = (int)s3.size();
        int n1 = (int)s1.size();
        int n2 = (int)s2.size();
        bitset<101> valid[101];
        bitset<101> memo[101];
        
        function<bool(int, int)> dfs = [&](int i1, int i2) -> bool
        {
            if (valid[i1][i2])
            {
                return memo[i1][i2];
            }
            valid[i1][i2] = true;
            int idx = i1 + i2;
            if (idx == n)
            {
                memo[i1][i2] = 1;
                return true;
            }
            bool ans = false;
            if (i1 < n1 && s1[i1] == s3[idx])
            {
                ans |= dfs(i1 + 1, i2);
            }
            if (i2 < n2 && s2[i2] == s3[idx])
            {
                ans |= dfs(i1, i2 + 1);
            }
            memo[i1][i2] = ans;
            return ans;
        };
        
        return dfs(0, 0);
    }
};
