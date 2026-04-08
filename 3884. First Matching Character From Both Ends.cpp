#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstMatchingIndex(const string& s)
    {
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == s[n - i - 1])
            {
                return i;
            }
        }
        return -1;
    }
};
