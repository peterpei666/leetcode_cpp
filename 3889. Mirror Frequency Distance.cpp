#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    char mirror(char c)
    {
        if (c >= 'a' && c <= 'z')
        {
            return 'z' - (c - 'a');
        }
        return '9' - (c - '0');
    }
    
public:
    int mirrorFrequency(const string& s)
    {
        int n = (int)s.size();
        int mp[128] = {0};
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            ans += abs(mp[c] - mp[mirror(c)]);
        }
        for (char c = '0'; c <= '9'; c++)
        {
            ans += abs(mp[c] - mp[mirror(c)]);
        }
        return ans / 2;
    }
};
