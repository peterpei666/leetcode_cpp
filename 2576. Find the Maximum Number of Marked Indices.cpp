#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n=(int)nums.size();
        int i=0;
        for(int j=n-n/2;j<n;j++)
        {
            if(2*nums[i]<=nums[j])
            {
                i++;
            }
        }
        return 2*i;
    }
};
