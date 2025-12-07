#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        if (!(low & 1))
        {
            low++;
        }
        return (high - low + 2) / 2;
    }
};
