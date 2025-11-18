#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int n = (int)bits.size();
        int i = 0;
        bool ans = true;
        while (i < n)
        {
            if (bits[i])
            {
                i += 2;
                ans = false;
            }
            else
            {
                i++;
                ans = true;
            }
        }
        return ans;
    }
};
