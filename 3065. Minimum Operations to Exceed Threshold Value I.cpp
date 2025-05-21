#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        int count=0;
        for(int i:nums)
        {
            if(i<k)
            {
                count++;
            }
        }
        return count;
    }
};
