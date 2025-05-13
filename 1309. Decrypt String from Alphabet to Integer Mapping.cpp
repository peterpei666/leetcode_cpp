#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string freqAlphabets(string s)
    {
        int i=0,n=(int)s.size();
        string ret="";
        while(i<n)
        {
            if(i+2<n&&s[i+2]=='#')
            {
                int t=(s[i]-'0')*10+s[i+1]-'0'-1;
                ret+='a'+t;
                i+=3;
            }
            else
            {
                int t=s[i]-'1';
                ret+='a'+t;
                i++;
            }
        }
        return ret;
    }
};
