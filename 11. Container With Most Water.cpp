#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int l = 0, r = (int)height.size() - 1;
        int ans = 0;
        while (l < r)
        {
            int temp = min(height[l], height[r]) * (r - l);
            ans = max(ans, temp);
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};
