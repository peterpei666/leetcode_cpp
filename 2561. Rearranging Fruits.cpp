#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2)
    {
        unordered_map<int,int> freq;
        int m=INT_MAX;
        for(int i:basket1)
        {
            freq[i]++;
            m=min(m,i);
        }
        for(int i:basket2)
        {
            freq[i]--;
            m=min(m,i);
        }
        vector<int> merge;
        for(auto& [k,c]:freq)
        {
            if(c%2)
            {
                return -1;
            }
            for(int i=0;i<abs(c)/2;i++)
            {
                merge.push_back(k);
            }
        }
        if(merge.empty())
        {
            return 0;
        }
        sort(merge.begin(),merge.end());
        long long ans=0;
        for(int i=0;i<merge.size()/2;i++)
        {
            ans+=min(2*m,merge[i]);
        }
        return ans;
    }
};
