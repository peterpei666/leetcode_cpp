#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxProduct(const vector<int>& nums)
    {
        long long a = 0, b = 0;
        for (int x : nums)
        {
            long long ax = abs(x);
            if (ax >= a)
            {
                b = a;
                a = ax;
            }
            else if (ax > b)
            {
                b = ax;
            }
        }
        return 100000LL * a * b;
    }
};
