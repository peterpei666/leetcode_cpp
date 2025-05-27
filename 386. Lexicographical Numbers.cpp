#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ret;
        for(int i=0,cur=1;i<n;i++)
        {
            ret.push_back(cur);
            if(cur*10<=n)
            {
                cur*=10;
            }
            else
            {
                while(cur%10==9||cur>=n)
                {
                    cur/=10;
                }
                cur++;
            }
        }
        return ret;
    }
};
