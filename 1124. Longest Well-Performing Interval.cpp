#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestWPI(vector<int>& hours)
    {
        int i,count=0,ret=0,hoursSize=(int)hours.size();
        int list[10001];
        for(i=0;i<10001;i++)
        {
            list[i]=-1;
        }
        for(i=0;i<hoursSize;i++)
        {
            count+=hours[i]>8?1:-1;
            if(count>0)
            {
                ret=i+1;
            }
            else
            {
                if(list[-count+1]==-1)
                {
                    list[-count+1]=i;
                }
                if(list[-count+2]!=-1)
                {
                    ret=max(ret,i-list[-count+2]);
                }
            }
        }
        return ret;
    }
};
