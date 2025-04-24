#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string minInteger(string num, int k)
    {
        int sz=(int)num.size();
        for(int i=0;i<sz&&k;i++)
        {
            if(num[i]=='0')
            {
                continue;
            }
            int pos=i;
            for(int j=i+1;j<sz&&j-i<=k;j++)
            {
                if(num[j]<num[pos])
                {
                    pos=j;
                }
            }
            if(pos!=i)
            {
                char temp=num[pos];
                for(int j=pos;j>i;j--)
                {
                    num[j]=num[j-1];
                }
                num[i]=temp;
                k-=pos-i;
            }
        }
        return num;
    }
};
