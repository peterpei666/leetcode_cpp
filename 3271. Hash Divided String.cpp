#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string stringHash(const string& s, int k)
    {
        string ret;
        int n=(int)s.size();
        for(int i=0;i<n;i+=k)
        {
            int hash=0;
            for(int j=0;j<k;j++)
            {
                hash+=s[i+j]-'a';
            }
            hash%=26;
            ret+=(char)('a'+hash);
        }
        return ret;
    }
};
