#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string clearStars(string s)
    {
        stack<int> list[26];
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='*')
            {
                list[s[i]-'a'].push(i);
            }
            else
            {
                for(int j=0;j<26;j++)
                {
                    if(!list[j].empty())
                    {
                        s[list[j].top()]='*';
                        list[j].pop();
                        break;
                    }
                }
            }
        }
        string ret="";
        for(char c:s)
        {
            if(c!='*')
            {
                ret.push_back(c);
            }
        }
        return ret;
    }
};
