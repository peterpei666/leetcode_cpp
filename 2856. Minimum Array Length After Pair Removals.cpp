#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minLengthAfterRemovals(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        for(int i:nums)
        {
            mp[i]++;
        }
        int m=0;
        for(auto [id,n]:mp)
        {
            m=max(m,n);
        }
        int n=(int)nums.size();
        if(m<=n/2)
        {
            return n%2;
        }
        else
        {
            return 2*m-n;
        }
    }
};
