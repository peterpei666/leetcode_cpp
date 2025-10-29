#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(const string& s)
    {
        int i = (int)s.size() - 1;
        int ans = 0;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        while (i >= 0 && s[i] != ' ')
        {
            i--;
            ans++;
        }
        return ans;
    }
};
