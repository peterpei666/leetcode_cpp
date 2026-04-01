#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string generateString(const string& str1, const string& str2)
    {
        int m = (int)str1.size();
        int n = (int)str2.size();
        string ans(m + n - 1, '?');
        for (int i = 0; i < m; i++)
        {
            if (str1[i] == 'F')
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (ans[i + j] != '?' && ans[i + j] != str2[j])
                {
                    return "";
                }
                ans[i + j] = str2[j];
            }
        }
        string old = ans;
        for (int i = 0; i < m + n - 1; i++)
        {
            if (ans[i] == '?')
            {
                ans[i] = 'a';
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (str1[i] == 'T' || string(ans.begin() + i, ans.begin() + i + n) != str2)
            {
                continue;
            }
            bool valid = false;
            for (int j = i + n - 1; j >= i; j--)
            {
                if (old[j] == '?')
                {
                    ans[j] = 'b';
                    valid = true;
                    break;
                }
            }
            if (!valid)
            {
                return "";
            }
        }
        return ans;
    }
};
