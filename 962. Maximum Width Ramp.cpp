#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int>& nums)
    {
        int n=(int)nums.size();
        vector<int> list(n);
        iota(list.begin(),list.end(),0);
        sort(list.begin(),list.end(),[&](int a,int b){ return nums[a]!=nums[b]?nums[a]<nums[b]:a<b; });
        int minidx=n;
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            maxlen=max(maxlen,list[i]-minidx);
            minidx=min(minidx,list[i]);
        }
        return maxlen;
    }
};
