#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        int n=(int)profits.size();
        pair<int,int> list[n];
        for(int i=0;i<n;i++)
        {
            list[i]={capital[i],profits[i]};
        }
        sort(&list[0],&list[0]+n);
        priority_queue<int> pq;
        int i=0;
        while(k)
        {
            while(i<n&&list[i].first<=w)
            {
                pq.push(list[i].second);
                i++;
            }
            if(pq.empty())
            {
                break;
            }
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
