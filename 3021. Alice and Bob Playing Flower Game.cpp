#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        return ((long long)n / 2) * ((m + 1) / 2) + ((long long)m / 2) * ((n + 1) / 2);
    }
};
