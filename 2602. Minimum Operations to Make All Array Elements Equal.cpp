#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries)
    {
        sort(nums.begin(),nums.end());
        int n=(int)nums.size();
        vector<long long> prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        int q=(int)queries.size();
        vector<long long> ret(q);
        for(int i=0;i<q;i++)
        {
            int p=(int)(lower_bound(nums.begin(),nums.end(),queries[i])-nums.begin());
            ret[i]=1LL*queries[i]*(2*p-n)+prefix[n]-2*prefix[p];
        }
        return ret;
    }
};
