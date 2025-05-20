#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> pq;
        for(int m:stones)
        {
            pq.push(m);
        }
        while(pq.size()>1)
        {
            int m1=pq.top();
            pq.pop();
            int m2=pq.top();
            pq.pop();
            m1-=m2;
            if(m1||pq.empty())
            {
                pq.push(m1);
            }
        }
        return pq.top();
    }
};

