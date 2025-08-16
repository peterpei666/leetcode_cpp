#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        int n=(int)nums.size();
        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<>> minheap;
        unordered_map<int,int> mp;
        int max_sz=0,min_sz=0;
        
        auto prune=[&](auto& heap)
        {
            while(!heap.empty())
            {
                int temp=heap.top();
                if(mp.count(temp))
                {
                    heap.pop();
                    mp[temp]--;
                    if(mp[temp]==0)
                    {
                        mp.erase(temp);
                    }
                }
                else
                {
                    break;
                }
            }
        };
        
        auto rebalance=[&]()
        {
            if(max_sz>min_sz+1)
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                max_sz--;
                min_sz++;
                prune(maxheap);
            }
            else if(min_sz>max_sz)
            {
                maxheap.push(minheap.top());
                minheap.pop();
                min_sz--;
                max_sz++;
                prune(minheap);
            }
        };
        
        for(int i=0;i<k;i++)
        {
            if(maxheap.empty()||nums[i]<=maxheap.top())
            {
                maxheap.push(nums[i]);
                max_sz++;
            }
            else
            {
                minheap.push(nums[i]);
                min_sz++;
            }
            rebalance();
        }
        vector<double> ans(n-k+1);
        if(k%2)
        {
            ans[0]=maxheap.top();
        }
        else
        {
            ans[0]=maxheap.top()/2.0+minheap.top()/2.0;
        }
        for(int i=k;i<n;i++)
        {
            if(!maxheap.empty()&&nums[i]<=maxheap.top())
            {
                maxheap.push(nums[i]);
                max_sz++;
            }
            else
            {
                minheap.push(nums[i]);
                min_sz++;
            }
            mp[nums[i-k]]++;
            if(nums[i-k]<=maxheap.top())
            {
                max_sz--;
                if(nums[i-k]==maxheap.top())
                {
                    prune(maxheap);
                }
            }
            else
            {
                min_sz--;
                if(!minheap.empty()&&nums[i-k]==minheap.top())
                {
                    prune(minheap);
                }
            }
            rebalance();
            if(k%2)
            {
                ans[i-k+1]=maxheap.top();
            }
            else
            {
                ans[i-k+1]=maxheap.top()/2.0+minheap.top()/2.0;
            }
        }
        return ans;
    }
};
