#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> divideString(const string& s, int k, char fill)
    {
        vector<string> ret;
        int i=0;
        while(i<s.size())
        {
            string temp;
            for(;i<s.size()&&temp.size()<k;i++)
            {
                temp+=s[i];
            }
            if(temp.size()==k)
            {
                ret.push_back(temp);
            }
            else
            {
                while(temp.size()<k)
                {
                    temp+=fill;
                }
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
