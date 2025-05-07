#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int>& target)
    {
        if(target.size()==1)
        {
            return target[0]==1;
        }
        priority_queue<int> pq;
        long long sum=0;
        for(int i:target)
        {
            sum+=i;
            pq.push(i);
        }
        while(pq.top()!=1)
        {
            int cur=pq.top();
            pq.pop();
            if(sum-cur==1)
            {
                return true;
            }
            int x=cur%(sum-cur);
            sum=sum-cur+x;
            if(x==0||x==cur)
            {
                return false;
            }
            pq.push(x);
        }
        return true;
    }
};
