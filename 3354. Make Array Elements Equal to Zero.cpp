#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countValidSelections(vector<int>& nums)
    {
        int n = (int)nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int temp = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            temp += nums[i];
            if (nums[i] == 0)
            {
                if (abs(2 * temp - sum) == 1)
                {
                    ans++;
                }
                else if (2 * temp == sum)
                {
                    ans += 2;
                }
            }
        }
        return ans;
    }
};
