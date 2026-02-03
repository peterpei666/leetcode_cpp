#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isTrionic(vector<int>& nums)
    {
        int n = (int)nums.size();
        int cnt = 1;
        int l = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return false;
            }
            if (cnt & 1)
            {
                if (nums[i] > nums[i + 1])
                {
                    if (l == 0)
                    {
                        return false;
                    }
                    cnt++;
                    l = 0;
                }
                l++;
            }
            else
            {
                if (nums[i] < nums[i + 1])
                {
                    if (l == 0)
                    {
                        return false;
                    }
                    cnt++;
                    l = 0;
                }
                l++;
            }
        }
        return cnt == 3 && l;
    }
};
