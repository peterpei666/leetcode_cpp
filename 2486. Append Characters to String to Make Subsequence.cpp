#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int appendCharacters(const string& s,const string& t)
    {
        int i,j=0;
        int n1=(int)s.size();
        int n2=(int)t.size();
        for(i=0;i<n1;i++)
        {
            if(j<n2&&s[i]==t[j])
            {
                j++;
            }
        }
        return n2-j;
    }
};
