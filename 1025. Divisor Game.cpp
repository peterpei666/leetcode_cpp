#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool divisorGame(int n)
    {
        return !(n&1);
    }
};
