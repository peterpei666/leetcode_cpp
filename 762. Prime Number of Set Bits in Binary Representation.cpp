#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            int cnt = __builtin_popcount(i);
            for (int j = 0; j < 10; j++)
            {
                if (cnt == prime[j])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
