#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void heapify_max(vector<int>& list, int i, int sz)
    {
        int largest = i;
        int l, r;
        while (1)
        {
            l = 2 * i + 1;
            r = 2 * i + 2;
            if (l < sz && list[l] > list[largest])
            {
                largest = l;
            }
            if (r < sz && list[r] > list[largest])
            {
                largest = r;
            }
            if (i == largest)
            {
                break;
            }
            swap(list[i], list[largest]);
            i = largest;
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums)
    {
        int n = (int)nums.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify_max(nums, i, n);
        }
        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            heapify_max(nums, 0, i);
        }
        return nums;
    }
};
