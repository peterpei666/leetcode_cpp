#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int>& nums)
    {
        int allodd=0;
        int alleven=0;
        for(int i:nums)
        {
            if(i%2)
            {
                allodd++;
            }
            else
            {
                alleven++;
            }
        }
        int oddeven=0;
        bool odd;
        odd=true;
        for(int i:nums)
        {
            if(i%2==odd)
            {
                odd^=1;
                oddeven++;
            }
        }
        int evenodd=0;
        odd=false;
        for(int i:nums)
        {
            if(i%2==odd)
            {
                odd^=1;
                evenodd++;
            }
        }
        return max(max(allodd,alleven),max(oddeven,evenodd));
    }
};
