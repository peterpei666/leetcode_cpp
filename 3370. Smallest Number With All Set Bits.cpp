#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n)
    {
        return (1 << (sizeof(int) * 8 - __builtin_clz(n))) - 1;
    }
};
