#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        int n=(int)nums.size(),k=0;
        int f1[2048];
        bitset<2048> found1;
        found1.set(0);
        f1[k]=0;
        k++;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int temp=nums[i]^nums[j];
                if(found1.test(temp)==false)
                {
                    found1.set(temp);
                    f1[k]=temp;
                    k++;
                }
            }
        }
        bitset<2048> ret;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                ret.set(nums[i]^f1[j]);
            }
        }
        return (int)ret.count();
    }
};
