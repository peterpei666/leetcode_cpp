#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 0;
        for (int k = 0; k < n; k++)
        {
            int count = 0;
            int sum = 0;
            for (int i = 1; i * i <= nums[k]; i++)
            {
                if (nums[k] % i == 0)
                {
                    int j = nums[k] / i;
                    count++;
                    sum += i;
                    if (i != j)
                    {
                        count++;
                        sum += j;
                    }
                    if (count > 4)
                    {
                        break;
                    }
                }
            }
            if (count == 4)
            {
                ans += sum;
            }
        }
        return ans;
    }
};
