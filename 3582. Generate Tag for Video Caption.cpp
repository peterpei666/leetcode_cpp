#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string generateTag(string caption)
    {
        int n=(int)caption.size();
        string ans="#";
        for(int i=0;i<n;i++)
        {
            if(caption[i]==' ')
            {
                continue;
            }
            if(i>0&&caption[i-1]==' ')
            {
                if(islower(caption[i]))
                {
                    caption[i]=toupper(caption[i]);
                }
            }
            else
            {
                if(isupper(caption[i]))
                {
                    caption[i]=tolower(caption[i]);
                }
            }
            ans+=caption[i];
        }
        if(ans.size()>=1)
        {
            ans[1]=tolower(ans[1]);
        }
        return ans.substr(0,100);
    }
};
