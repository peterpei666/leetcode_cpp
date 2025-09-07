#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(const string& s)
    {
        int n = (int)s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (26 + 'a' - s[i]) % 26);
        }
        return ans;
    }
};
