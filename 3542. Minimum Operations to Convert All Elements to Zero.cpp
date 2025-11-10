#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
private:
    int stk[100000];
    
    int check(vector<int>& nums, int l, int r)
    {
        int k = 0;
        int ans = 0;
        for (int i = l; i < r; i++)
        {
            while (k && stk[k - 1] > nums[i])
            {
                k--;
                ans++;
            }
            while (k && stk[k - 1] == nums[i])
            {
                k--;
            }
            stk[k] = nums[i];
            k++;
        }
        return ans + k;
    }
    
public:
    int minOperations(vector<int>& nums)
    {
        int ans = 0;
        int l = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans += check(nums, l, i);
                l = i + 1;
            }
        }
        ans += check(nums, l, n);
        return ans;
    }
};
