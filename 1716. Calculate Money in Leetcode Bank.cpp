#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        int temp[7] = {0};
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 7 == 0)
            {
                temp[0]++;
                ans += temp[0];
            }
            else
            {
                temp[i % 7] = temp[(i - 1) % 7] + 1;
                ans += temp[i % 7];
            }
        }
        return ans;
    }
};
