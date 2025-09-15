#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findIntegers(int n)
    {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        int i = 30;
        int ans = 0;
        int prev = 0;
        while (i >= 0)
        {
            if (n & (1 << i))
            {
                ans += f[i];
                if (prev == 1)
                {
                    ans--;
                    break;
                }
                prev = 1;
            }
            else
            {
                prev = 0;
            }
            i--;
        }
        return ans + 1;
    }
};
