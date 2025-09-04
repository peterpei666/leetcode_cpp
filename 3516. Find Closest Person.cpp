#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int a = abs(x - z);
        int b = abs(y - z);
        if (a == b)
        {
            return 0;
        }
        else if (a > b)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
};
