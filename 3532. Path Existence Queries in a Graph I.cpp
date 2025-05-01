#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
    {
        vector<int> group(n);
        group[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<=maxDiff)
            {
                group[i]=group[i-1];
            }
            else
            {
                group[i]=group[i-1]+1;
            }
        }
        vector<bool> ret(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            ret[i]=(group[queries[i][0]]==group[queries[i][1]]);
        }
        return ret;
    }
};
