#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int digit(int x)
    {
        int c=0;
        while(x)
        {
            c+=x%10;
            x/=10;
        }
        return c;
    }
    
    int countLargestGroup(int n)
    {
        short count[36]={0};
        for(int i=1;i<=n;i++)
        {
            int m=digit(i);
            count[m-1]++;
        }
        int max=0,c=0;
        for(short l:count)
        {
            if(l>max)
            {
                max=l;
                c=1;
            }
            else if(l==max)
            {
                c++;
            }
        }
        return c;
    }
};
