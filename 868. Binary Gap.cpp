#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int ans = 0;
        int temp = INT_MIN;
        while (n)
        {
            if (n & 1)
            {
                ans = max(ans, temp);
                temp = 0;
            }
            n >>= 1;
            temp++;
        }
        return ans;
    }
};
