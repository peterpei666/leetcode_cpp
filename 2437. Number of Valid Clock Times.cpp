#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    public:
    int countTime(string time)
    {
        int total=1;
        if(time[0]=='?'&&time[1]=='?')
        {
            total*=24;
        }
        else if(time[0]=='?')
        {
            if(time[1]<'4')
            {
                total*=3;
            }
            else
            {
                total*=2;
            }
        }
        else if(time[1]=='?')
        {
            if(time[0]>'2')
            {
                return 0;
            }
            else if(time[0]=='2')
            {
                total*=4;
            }
            else
            {
                total*=10;
            }
        }
        else
        {
            if((time[0]-'0')*10+time[1]-'0'>=24)
            {
                return 0;
            }
        }
        if(time[3]=='?'&&time[4]=='?')
        {
            return total*60;
        }
        if(time[3]=='?')
        {
            total*=6;
        }
        else if(time[3]>'5')
        {
            return 0;
        }
        if(time[4]=='?')
        {
            total*=10;
        }
        return total;
    }
};
