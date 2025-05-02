#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution1
{
public:
    int numTimesAllBlue(vector<int>& flips)
    {
        int n=(int)flips.size();
        bitset<50000> mp;
        int c1=0,c2=0,count=0;
        for(int i=0;i<n;i++)
        {
            if(mp.test(i))
            {
                c1++;
                c2--;
            }
            int p=flips[i]-1;
            mp.flip(p);
            if(p<=i)
            {
                if(mp.test(p))
                {
                    c1++;
                }
                else
                {
                    c1--;
                }
            }
            else
            {
                if(mp.test(p))
                {
                    c2++;
                }
                else
                {
                    c2--;
                }
            }
            if(c1==i+1&&c2==0)
            {
                count++;
            }
        }
        return count;
    }
};

class Solution
{
public:
    int numTimesAllBlue(vector<int>& flips)
    {
        int count=0,maxPos=0,sz;
        sz=(int)flips.size();
        for(int i=0;i<sz;i++)
        {
            if(flips[i]>maxPos)
            {
                maxPos=flips[i];
            }
            if(maxPos==i+1)
            {
                count++;
            }
        }
        return count;
    }
};

