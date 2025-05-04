#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n=(int)nums.size(),m=(int)queries.size();
        vector<int> dif(n+1,0);
        for(int i=0;i<m;i++)
        {
            dif[queries[i][0]]--;
            dif[queries[i][1]+1]++;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=dif[i];
            if(nums[i]+sum>0)
            {
                return false;
            }
        }
        return true;
    }
};
