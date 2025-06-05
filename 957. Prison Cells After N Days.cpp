#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n)
    {
        bitset<1<<6> list;
        vector<unsigned char> day;
        unsigned char temp=0;
        for(int i=1;i<7;i++)
        {
            if(cells[i-1]==cells[i+1])
            {
                temp|=1<<i;
            }
        }
        while(list.test(temp>>1)==false)
        {
            list.set(temp>>1);
            day.push_back(temp);
            unsigned char next=0;
            for(int i=1;i<7;i++)
            {
                if(((temp&(1<<(i-1)))>0)==((temp&(1<<(i+1)))>0))
                {
                    next|=1<<i;
                }
            }
            temp=next;
        }
        int l=0;
        for(l=0;l<day.size();l++)
        {
            if(day[l]==temp)
            {
                break;
            }
        }
        int cycle=(int)day.size()-l;
        int idx;
        if(n<=l)
        {
            idx=n-1;
        }
        else
        {
            n=(n-l)%cycle;
            if(n==0)
            {
                idx=(int)day.size()-1;
            }
            else
            {
                idx=l+n-1;
            }
        }
        vector<int> ret(8,0);
        for(int i=1;i<7;i++)
        {
            if(day[idx]&(1<<i))
            {
                ret[i]=1;
            }
        }
        return ret;
    }
};
