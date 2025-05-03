#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int digit(int x)
    {
        int count=0;
        while(x)
        {
            count++;
            x/=10;
        }
        return count;
    }
    
    int findNumbers(vector<int>& nums)
    {
        int count=0;
        for(int i:nums)
        {
            if(digit(i)%2==0)
            {
                count++;
            }
        }
        return count;
    }
};
