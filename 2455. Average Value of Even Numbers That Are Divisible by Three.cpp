#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int averageValue(vector<int>& nums)
    {
        int sum=0,count=0;
        for(int i:nums)
        {
            if(i%6==0)
            {
                sum+=i;
                count++;
            }
        }
        return count?sum/count:0;
    }
};
