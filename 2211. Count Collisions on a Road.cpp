#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countCollisions(const string& directions)
    {
        int n = (int)directions.size();
        int l = 0, r = n - 1;
        while (l < n && directions[l] == 'L')
        {
            l++;
        }
        while (r >= 0 && directions[r] == 'R')
        {
            r--;
        }
        int ans = r - l + 1;
        for (int i = l; i <= r; i++)
        {
            ans -= directions[i] == 'S';
        }
        return ans;
    }
};
