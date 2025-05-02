#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int freq[26]={0};
        for(char a:tasks)
        {
            freq[a-'A']++;
        }
        priority_queue<int> pq;
        for(int i:freq)
        {
            if(i)
            {
                pq.push(i);
            }
        }
        int time=0;
        while(!pq.empty())
        {
            int l=n+1,t=0;
            vector<int> temp;
            while(!pq.empty()&&l)
            {
                l--;
                t++;
                temp.push_back(pq.top()-1);
                pq.pop();
            }
            for(int i:temp)
            {
                if(i>0)
                {
                    pq.push(i);
                }
            }
            time+=pq.empty()?t:n+1;
        }
        return time;
    }
};
