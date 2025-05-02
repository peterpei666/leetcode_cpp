#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lens;
    
    bool check(string& s,string& m)
    {
        int t=(int)m.size();
        for(int i=0,j=0;i<lens;i++)
        {
            if(m[j]==s[i])
            {
                j++;
                if(t==j)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    string findLongestWord(string s, vector<string>& dictionary)
    {
        sort(dictionary.begin(),dictionary.end(),[](const string& a,const string& b) { if(a.size()!=b.size()) return a.size()>b.size(); return a<b;});
        lens=(int)s.size();
        for(string& i:dictionary)
        {
            if(check(s,i))
            {
                return i;
            }
        }
        return "";
    }
};
