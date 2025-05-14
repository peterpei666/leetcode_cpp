#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int>& nums, int k)
    {
        int len=10000000;
        for(int i:nums)
        {
            if(i==0)
            {
                len++;
            }
            else
            {
                if(len<k)
                {
                    return false;
                }
                len=0;
            }
        }
        return true;
    }
};
