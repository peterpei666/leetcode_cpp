#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries)
    {
        sort(queries.begin(),queries.end(),[](const vector<int>& a,const vector<int>& b){return a[0]<b[0];});
        priority_queue<int> pq;
        vector<int> delta(nums.size()+1,0);
        int cnt=0;
        for(int i=0,j=0;i<nums.size();i++)
        {
            cnt+=delta[i];
            while(j<queries.size()&&queries[j][0]==i)
            {
                pq.push(queries[j][1]);
                j++;
            }
            while(cnt<nums[i]&&!pq.empty()&&pq.top()>=i)
            {
                cnt++;
                delta[pq.top()+1]--;
                pq.pop();
            }
            if(cnt<nums[i])
            {
                return -1;
            }
        }
        return (int)pq.size();
    }
};
