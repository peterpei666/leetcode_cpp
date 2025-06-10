#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string decodeString(const string& s)
    {
        string ret="";
        int cur=0;
        stack<pair<int,int>> list;
        for(char c:s)
        {
            if(isdigit(c))
            {
                cur=cur*10+c-'0';
            }
            else if(c=='[')
            {
                list.push({cur,(int)ret.size()});
                cur=0;
            }
            else if(c==']')
            {
                int start=list.top().second;
                int end=(int)ret.size();
                for(int i=0;i<list.top().first-1;i++)
                {
                    ret.append(ret,start,end-start);
                }
                list.pop();
            }
            else
            {
                ret+=c;
            }
        }
        return ret;
    }
};
