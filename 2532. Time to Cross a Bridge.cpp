#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time)
    {
        priority_queue<pair<int,int>> left,right;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> up,down;
        for(int i=0;i<time.size();i++)
        {
            left.push({time[i][0]+time[i][2],i});
        }
        int t=0;
        while(n)
        {
            if(!right.empty())
            {
                auto [dt,i]=right.top();
                right.pop();
                t+=time[i][2];
                down.push({t+time[i][3],i});
            }
            else if(!left.empty())
            {
                auto [dt,i]=left.top();
                left.pop();
                t+=time[i][0];
                up.push({t+time[i][1],i});
                n--;
            }
            else
            {
                if(up.empty())
                {
                    t=down.top().first;
                }
                else if(down.empty())
                {
                    t=up.top().first;
                }
                else
                {
                    t=min(down.top().first,up.top().first);
                }
            }
            while(!up.empty()&&up.top().first<=t)
            {
                auto [dt,i]=up.top();
                up.pop();
                right.push({time[i][0]+time[i][2],i});
            }
            while(!down.empty()&&down.top().first<=t)
            {
                auto [dt,i]=down.top();
                down.pop();
                left.push({time[i][0]+time[i][2],i});
            }
        }
        while(!right.empty())
        {
            auto [dt,i]=right.top();
            right.pop();
            t+=time[i][2];
            while(!up.empty()&&up.top().first<=t)
            {
                auto [dt,i]=up.top();
                up.pop();
                right.push({time[i][0]+time[i][2],i});
            }
        }
        while(!up.empty())
        {
            auto [dt,i]=up.top();
            up.pop();
            t=max(t,dt);
            t+=time[i][2];
        }
        return t;
    }
};
