#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        int l = 0, r = x;
        int ans = 0;
        while (l < r)
        {
            long long mid = (l * 1LL + r * 1LL) / 2;
            long long temp = mid * mid;
            if (temp > x)
            {
                r = (int)mid;
            }
            else
            {
                ans = (int)mid;
                l = (int)mid + 1;
            }
        }
        return ans;
    }
};
