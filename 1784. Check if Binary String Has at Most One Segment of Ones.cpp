#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkOnesSegment(const string& s)
    {
        int ans = 0;
        int n = (int)s.size();
        for (int i = 1; i < n; i++)
        {
            ans += abs(s[i] - s[i - 1]);
        }
        return ans == 0 || ans == 1;
    }
};
