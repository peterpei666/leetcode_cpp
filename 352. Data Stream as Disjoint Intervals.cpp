#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class SummaryRanges
{
private:
    int l,r;
    bitset<10001> mp;
    
public:
    SummaryRanges()
    {
        l=10001;
        r=0;
        mp.reset();
    }
    
    void addNum(int value)
    {
        l=min(l,value);
        r=max(r,value);
        mp.set(value);
    }
    
    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        vector<int> temp(2);
        for(int i=l;i<=r;i++)
        {
            if(mp.test(i))
            {
                temp[0]=i;
                i++;
                while(i<=r&&mp.test(i))
                {
                    i++;
                }
                temp[1]=i-1;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
