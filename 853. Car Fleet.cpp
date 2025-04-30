#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        vector<pair<int,double>> list(position.size());
        for(int i=0;i<position.size();i++)
        {
            list[i]={position[i],(double)(target-position[i])/1.0/speed[i]};
        }
        sort(list.begin(),list.end());
        int count=0;
        double time=0.0;
        for(int i=(int)position.size()-1;i>=0;i--)
        {
            if(list[i].second>time)
            {
                count++;
                time=list[i].second;
            }
        }
        return count;
    }
};
