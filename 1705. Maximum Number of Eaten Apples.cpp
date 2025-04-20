#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int eatenApples(vector<int>& apples, vector<int>& days)
    {
        using p=pair<int,int>;
        priority_queue<p,vector<p>,greater<p>> queue;
        int n=(int)apples.size();
        int d=0,count=0;
        while(d<n||!queue.empty())
        {
            if(d<n&&apples[d]>0)
            {
                queue.push({d+days[d],apples[d]});
            }
            while(!queue.empty()&&(queue.top().first<=d||queue.top().second<=0))
            {
                queue.pop();
            }
            if(!queue.empty())
            {
                p top=queue.top();
                queue.pop();
                top.second--;
                count++;
                if(top.second>0)
                {
                    queue.push(top);
                }
            }
            d++;
        }
        return count;
    }
};
