#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int encrypt(int x)
    {
        int c=0,m=0;
        while(x)
        {
            c++;
            m=max(m,x%10);
            x/=10;
        }
        while(c)
        {
            x*=10;
            x+=m;
            c--;
        }
        return x;
    }
    
    int sumOfEncryptedInt(vector<int>& nums)
    {
        int sum=0;
        for(int i:nums)
        {
            sum+=encrypt(i);
        }
        return sum;
    }
};
