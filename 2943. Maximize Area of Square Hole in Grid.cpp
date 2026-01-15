#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hs = (int)hBars.size();
        int vs = (int)vBars.size();
        int h = 1, v = 1;
        int temp = 1;
        for (int i = 1; i < hs; i++)
        {
            if (hBars[i] == hBars[i - 1] + 1)
            {
                temp++;
            }
            else
            {
                temp = 1;
            }
            h = max(h, temp);
        }
        temp = 1;
        for (int i = 1; i < vs; i++)
        {
            if (vBars[i] == vBars[i - 1] + 1)
            {
                temp++;
            }
            else
            {
                temp = 1;
            }
            v = max(v, temp);
        }
        return (min(h, v) + 1) * (min(h, v) + 1);
    }
};
