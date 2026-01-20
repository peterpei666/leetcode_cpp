#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int vowelConsonantScore(const string& s)
    {
        int n = (int)s.size();
        int v = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                v++;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                c++;
            }
        }
        if (c == 0)
        {
            return 0;
        }
        return v / c;
    }
};
