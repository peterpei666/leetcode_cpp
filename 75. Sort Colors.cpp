#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int c[3]={0};
        for(int i:nums)
        {
            c[i]++;
        }
        int p=0;
        while(c[0])
        {
            nums[p]=0;
            c[0]--;
            p++;
        }
        while(c[1])
        {
            nums[p]=1;
            c[1]--;
            p++;
        }
        while(c[2])
        {
            nums[p]=2;
            c[2]--;
            p++;
        }
    }
};
