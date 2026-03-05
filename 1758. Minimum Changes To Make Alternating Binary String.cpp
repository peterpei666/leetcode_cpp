#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(const string& s)
    {
        int n = (int)s.size();
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            ans1 += (s[i] - '0') ^ (i & 1);
            ans2 += (s[i] - '0') ^ (i & 1) ^ 1;
        }
        return min(ans1, ans2);
    }
};
