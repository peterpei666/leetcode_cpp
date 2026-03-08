#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        int n = (int)nums.size();
        unordered_set<string> mp(nums.begin(), nums.end());
        string s(n, '0');
        for (int i = 0; i <= n; i++)
        {
            if (!mp.count(s))
            {
                return s;
            }
            for (int i = n - 1, j = 1; j; i--)
            {
                s[i]++;
                j = (s[i] - '0') / 2;
                s[i] = (s[i] - '0') % 2 + '0';
            }
        }
        return s;
    }
};
