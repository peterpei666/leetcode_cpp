#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCost(int n)
    {
        return n * (n - 1) / 2;
    }
};
