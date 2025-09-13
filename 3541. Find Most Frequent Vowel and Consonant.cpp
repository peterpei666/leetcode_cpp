#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maxFreqSum(const string& s)
    {
        int cnt[26] = {0};
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
        }
        char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
        int t1 = 0, t2 = 0;
        for (int i = 0; i < 26; i++)
        {
            bool v = false;
            for (int j = 0; j < 5; j++)
            {
                if (i == vowel[j] - 'a')
                {
                    v = true;
                    break;
                }
            }
            if (v)
            {
                t1 = max(t1, cnt[i]);
            }
            else
            {
                t2 = max(t2, cnt[i]);
            }
        }
        return t1 + t2;
    }
};
