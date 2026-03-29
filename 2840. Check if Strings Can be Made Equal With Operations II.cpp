#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkStrings(const string& s1, const string& s2)
    {
        int n = (int)s1.size();
        int cnt[2][26] = {0};
        for (int i = 0; i < n; i++)
        {
            cnt[i & 1][s1[i] - 'a']++;
            cnt[i & 1][s2[i] - 'a']--;
        }
        int target[26] = {0};
        return memcmp(cnt[0], target, sizeof(target)) == 0 && memcmp(cnt[1], target, sizeof(target)) == 0;
    }
};
