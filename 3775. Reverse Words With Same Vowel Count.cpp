#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int cnt = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int temp = 0, start = i;
            while (i < s.size() && s[i] != ' ')
            {
                if (st.count(s[i]))
                {
                    temp++;
                }
                i++;
            }
            if (temp == cnt)
            {
                reverse(s.begin() + start, s.begin() + i);
            }
            if (cnt == -1)
            {
                cnt = temp;
            }
        }
        return s;
    }
};
