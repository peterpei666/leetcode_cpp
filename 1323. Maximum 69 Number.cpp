#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        int temp=num,ans=0,i=1;
        while(temp)
        {
            if(temp%10==6)
            {
                ans=3*i;
            }
            i*=10;
            temp/=10;
        }
        return num+ans;
    }
};
