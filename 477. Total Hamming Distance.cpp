#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int totalHammingDistance(vector<int>& nums)
    {
        int bit[32]={0};
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            int temp=nums[i];
            for(int j=0;temp;j++,temp>>=1)
            {
                if(temp&1)
                {
                    bit[j]++;
                }
            }
        }
        int sum=0;
        for(int i=0;i<32;i++)
        {
            sum+=bit[i]*(n-bit[i]);
        }
        return sum;
    }
};
