#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes)
    {
        bitset<1000> open;
        bitset<1000> have;
        bitset<1000> used;
        int n=(int)status.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(status[i])
            {
                open.set(i);
            }
        }
        queue<int> q;
        for(int i:initialBoxes)
        {
            have.set(i);
            if(open.test(i))
            {
                q.push(i);
                used.set(i);
                ans+=candies[i];
            }
        }
        while(!q.empty())
        {
            int box=q.front();
            q.pop();
            for(int key:keys[box])
            {
                open.set(key);
                if(!used.test(key)&&have.test(key))
                {
                    q.push(key);
                    used.set(key);
                    ans+=candies[key];
                }
            }
            for(int key:containedBoxes[box])
            {
                have.set(key);
                if(!used.test(key)&&open.test(key))
                {
                    q.push(key);
                    used.set(key);
                    ans+=candies[key];
                }
            }
        }
        return ans;
    }
};
