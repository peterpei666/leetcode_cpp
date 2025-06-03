#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int sum=0;
        for(int i:nums)
        {
            if(i%2==0)
            {
                sum+=i;
            }
        }
        int n=(int)queries.size();
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            if(nums[queries[i][1]]%2==0)
            {
                sum-=nums[queries[i][1]];
            }
            nums[queries[i][1]]+=queries[i][0];
            if(nums[queries[i][1]]%2==0)
            {
                sum+=nums[queries[i][1]];
            }
            ret[i]=sum;
        }
        return ret;
    }
};
