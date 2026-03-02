#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int>& nums)
    {
        int n = (int)nums.size();
        int mid = (n + 1) / 2;
        vector<int> l(mid);
        vector<int> r(n - mid);
        sort(nums.begin(), nums.end());
        copy(nums.begin(), nums.begin() + mid, l.begin());
        copy(nums.begin() + mid, nums.end(), r.begin());
        reverse(l.begin(), l.end());
        reverse(r.begin(), r.end());
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                nums[i] = r[i >> 1];
            }
            else
            {
                nums[i] = l[i >> 1];
            }
        }
    }
};
