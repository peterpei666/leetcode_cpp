#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int canBeTypedWords(const string& text, const string& brokenLetters)
    {
        bitset<26> mp;
        for (char c : brokenLetters)
        {
            mp.set(c - 'a');
        }
        int n = (int)text.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int valid = 1;
            while (i < n && text[i] != ' ')
            {
                if (mp.test(text[i] - 'a'))
                {
                    valid = 0;
                }
                i++;
            }
            ans += valid;
        }
        return ans;
    }
};
