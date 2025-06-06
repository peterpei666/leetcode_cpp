#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string robotWithString(const string& s)
    {
        int cnt[26]={0};
        for(char c:s)
        {
            cnt[c-'a']++;
        }
        stack<char> t;
        string ret="";
        int minc=0;
        for(char c:s)
        {
            t.push(c);
            cnt[c-'a']--;
            while(minc+'a'<'z'&&cnt[minc]==0)
            {
                minc++;
            }
            while(!t.empty()&&t.top()-'a'<=minc)
            {
                ret.push_back(t.top());
                t.pop();
            }
        }
        return ret;
    }
};
