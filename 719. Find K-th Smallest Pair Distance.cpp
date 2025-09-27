#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
private:
    static inline int count(vector<int>& nums, int n, int mid)
    {
        int cnt = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < n && nums[j] - nums[i] <= mid)
            {
                j++;
            }
            cnt += j - i - 1;
        }
        return cnt;
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int l = 0, r = nums[n - 1] - nums[0];
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (count(nums, n, mid) < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
