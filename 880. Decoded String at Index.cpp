#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long l=0;
        for(char& c:s)
        {
            if(c>'0'&&c<='9')
            {
                l*=c-'0';
            }
            else
            {
                l++;
            }
        }
        for(int i=(int)s.size()-1;i>=0;i--)
        {
            if(s[i]>'0'&&s[i]<='9')
            {
                l/=s[i]-'0';
                k%=l;
            }
            else
            {
                if(k==0||l==k)
                {
                    return string("")+s[i];
                }
                l--;
            }
        }
        return "";
    }
};


