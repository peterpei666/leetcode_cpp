#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int cost(int mins,int secs,int startAt, int moveCost, int pushCost)
    {
        if(mins>99||secs>99||mins<0||secs<0)
        {
            return INT_MAX;
        }
        string s=to_string(mins*100+secs);
        int ret=0;
        char cur='0'+startAt;
        for(char c:s)
        {
            if(c==cur)
            {
                ret+=pushCost;
            }
            else
            {
                cur=c;
                ret+=pushCost+moveCost;
            }
        }
        return ret;
    }
    
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        int mins=targetSeconds/60;
        int secs=targetSeconds%60;
        return min(cost(mins,secs,startAt,moveCost,pushCost),cost(mins-1,secs+60,startAt,moveCost,pushCost));
    }
};
