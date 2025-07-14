#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long taskSchedulerII(vector<int>& tasks, int space)
    {
        unordered_map<long long,long long> mp;
        int n=(int)tasks.size();
        long long cur=0;
        for(int i=0;i<n;i++)
        {
            if(mp.count(tasks[i]))
            {
                if(mp[tasks[i]]>cur)
                {
                    cur=mp[tasks[i]];
                }
                cur++;
                mp[tasks[i]]=cur+space;
            }
            else
            {
                cur++;
                mp[tasks[i]]=cur+space;
            }
        }
        return cur;
    }
};
