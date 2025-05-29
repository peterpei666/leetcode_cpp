#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeStars(const string& s)
    {
        stack<char> list;
        for(char c:s)
        {
            if(c!='*')
            {
                list.push(c);
            }
            else
            {
                list.pop();
            }
        }
        string ret="";
        while(!list.empty())
        {
            char temp=list.top();
            list.pop();
            ret+=temp;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
