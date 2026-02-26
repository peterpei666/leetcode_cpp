#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numSteps(const string& s)
    {
        int n = (int)s.size();
        int ans = n;
        int i = n - 1;
        while (i >= 0 && s[i] == '0')
        {
            i--;
        }
        ans += (i > 0) - (i == 0);
        while (i >= 0)
        {
            ans += s[i] == '0';
            i--;
        }
        return ans;
    }
};
