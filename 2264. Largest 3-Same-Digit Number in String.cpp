#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(const string& num)
    {
        int n=(int)num.size();
        string ans;
        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1]&&num[i]==num[i+2])
            {
                if(ans.size()==0||ans[0]<num[i])
                {
                    ans=string(3,num[i]);
                }
            }
        }
        return ans;
    }
};
