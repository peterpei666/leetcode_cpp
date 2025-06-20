#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int i,j,ans=0;
        int n=(int)s.size();
        char temp1[n];
        char temp2[n];
        if(y>x)
        {
            swap(x,y);
            for(i=0;i<n;i++)
            {
                if(s[i]=='a')
                {
                    s[i]='b';
                }
                else if(s[i]=='b')
                {
                    s[i]='a';
                }
            }
        }
        for(i=0,j=0;i<n;i++)
        {
            if(s[i]=='b'&&j&&temp1[j-1]=='a')
            {
                j--;
                ans+=x;
            }
            else
            {
                temp1[j]=s[i];
                j++;
            }
        }
        n=j;
        for(i=0,j=0;i<n;i++)
        {
            if(temp1[i]=='a'&&j&&temp2[j-1]=='b')
            {
                j--;
                ans+=y;
            }
            else
            {
                temp2[j]=temp1[i];
                j++;
            }
        }
        return ans;
    }
};
