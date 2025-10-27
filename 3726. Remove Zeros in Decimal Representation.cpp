#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long removeZeros(long long n)
    {
        long long ans = 0;
        long long temp = 1;
        while (n)
        {
            if (n % 10)
            {
                ans += (n % 10) * temp;
                temp *= 10;
            }
            n /= 10;
        }
        return ans;
    }
};
