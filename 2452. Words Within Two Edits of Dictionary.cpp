#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary)
    {
        sort(dictionary.begin(),dictionary.end(),[&](const string& a,const string& b) { return a.size()<b.size(); });
        vector<string> ret;
        for(const string& s:queries)
        {
            int sz=(int)s.size();
            for(const string& w:dictionary)
            {
                if(w.size()<sz)
                {
                    continue;
                }
                if(w.size()>sz)
                {
                    break;
                }
                int cnt=0;
                for(int i=0;i<sz;i++)
                {
                    if(w[i]!=s[i])
                    {
                        cnt++;
                        if(cnt>2)
                        {
                            break;
                        }
                    }
                }
                if(cnt<=2)
                {
                    ret.push_back(s);
                    break;
                }
            }
        }
        return ret;
    }
};
