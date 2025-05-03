#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        int ret=INT_MAX,sz;
        sz=(int)tops.size();
        for(int i=1;i<=6;i++)
        {
            int temp1=0,temp2=0;
            int p;
            for(p=0;p<sz;p++)
            {
                if(tops[p]!=i&&bottoms[p]==i)
                {
                    temp1++;
                }
                if(tops[p]==i&&bottoms[p]!=i)
                {
                    temp2++;
                }
                if(tops[p]!=i&&bottoms[p]!=i)
                {
                    break;
                }
            }
            if(p==sz)
            {
                ret=min(ret,min(temp1,temp2));
            }
        }
        if(ret==INT_MAX)
        {
            return -1;
        }
        return ret;
    }
};
