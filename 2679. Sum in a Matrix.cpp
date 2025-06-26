#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int matrixSum(vector<vector<int>>& nums)
    {
        int m,n;
        int sum=0;
        m=(int)nums.size();
        n=(int)nums[0].size();
        for(auto& row:nums)
        {
            sort(row.begin(),row.end(),greater<int>());
        }
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<m;j++)
            {
                temp=max(temp,nums[j][i]);
            }
            sum+=temp;
        }
        return sum;
    }
};
