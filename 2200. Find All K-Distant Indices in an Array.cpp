#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        bitset<1000> list;
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)
            {
                for(int j=max(0,i-k);j<=min(i+k,n-1);j++)
                {
                    list.set(j);
                }
            }
        }
        vector<int> ret;
        for(int i=0;i<1000;i++)
        {
            if(list.test(i))
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
