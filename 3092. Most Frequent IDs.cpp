#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    struct p
    {
        int id;
        long long f;
    };
    
    struct cmp
    {
        bool operator()(const p& a, const p& b)
        {
            return a.f<b.f;
        }
    };
    
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq)
    {
        unordered_map<int,long long> list;
        vector<long long> ret(nums.size());
        priority_queue<p,vector<p>,cmp> pq;
        int n=(int)nums.size();
        long long m=0;
        for(int i=0;i<n;i++)
        {
            list[nums[i]]+=freq[i];
            pq.push({nums[i],list[nums[i]]});
            while(!pq.empty())
            {
                auto [id,f]=pq.top();
                if(list[id]==f)
                {
                    break;
                }
                pq.pop();
            }
            ret[i]=pq.top().f;
        }
        return ret;
    }
};

