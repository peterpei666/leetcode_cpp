#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int,int> list;
        int cnt=0,sum=0;
        int n=(int)nums.size();
        list[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(list.count(sum-k))
            {
                cnt+=list[sum-k];
            }
            list[sum]++;
        }
        return cnt;
    }
};
