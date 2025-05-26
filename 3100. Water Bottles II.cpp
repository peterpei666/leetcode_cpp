#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int cnt=numBottles,empty=numBottles;
        while(empty>=numExchange)
        {
            empty-=numExchange;
            cnt++;
            empty++;
            numExchange++;
        }
        return cnt;
    }
};
