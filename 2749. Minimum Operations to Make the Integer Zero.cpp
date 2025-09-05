#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        for (int i = 1; i < 60; i++)
        {
            long long x = num1 - (long long)num2 * i;
            if (x < i)
            {
                break;
            }
            if (i >= __builtin_popcountll(x))
            {
                return i;
            }
        }
        return -1;
    }
};
