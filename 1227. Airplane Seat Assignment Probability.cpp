#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        return n == 1 ? 1.0 : 0.5;
    }
};
