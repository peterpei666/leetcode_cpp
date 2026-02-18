#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int k = -1;
        while (n)
        {
            if (k == (n & 1))
            {
                return false;
            }
            k = n & 1;
            n >>= 1;
        }
        return true;
    }
};
