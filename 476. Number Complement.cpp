#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findComplement(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        int ans = 0;
        for (int i = 0; i < 31 && (1 << i) <= n; i++)
        {
            if ((n & (1 << i)) == 0)
            {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};
