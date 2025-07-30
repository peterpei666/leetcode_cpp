#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string getPermutation(int n,int k)
    {
        k--;
        short used=0;
        string s(n,'0');
        int factorial[9];
        factorial[0]=1;
        for(int i=1;i<9;i++)
        {
            factorial[i]=factorial[i-1]*i;
        }
        for(int i=0;i<n;i++)
        {
            int m=k/factorial[n-i-1];
            k%=factorial[n-i-1];
            for(int j=1;j<=n;j++)
            {
                if(used&(1<<j))
                {
                    continue;
                }
                if(m==0)
                {
                    used|=1<<j;
                    s[i]+=j;
                    break;
                }
                else
                {
                    m--;
                }
            }
        }
        return s;
    }
};
