#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool valid(string s)
    {
        int len=(int)s.size();
        if(len==0||len>3)
        {
            return false;
        }
        if(s[0]=='0'&&len!=1)
        {
            return false;
        }
        int val=stoi(s);
        return val<256;
    }
    
    vector<string> restoreIpAddresses(string s)
    {
        int len=(int)s.size();
        vector<string> ret;
        if(len<4||len>12)
        {
            return ret;
        }
        for(int i=1;i<4&&i<len;i++)
        {
            for(int j=i+1;j<i+4&&j<len;j++)
            {
                for(int k=j+1;k<j+4&&k<len;k++)
                {
                    string a=s.substr(0,i);
                    string b=s.substr(i,j-i);
                    string c=s.substr(j,k-j);
                    string d=s.substr(k);
                    if(valid(a)&&valid(b)&&valid(c)&&valid(d))
                    {
                        ret.push_back(a+"."+b+"."+c+"."+d);
                    }
                }
            }
        }
        return ret;
    }
};
