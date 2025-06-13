#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int>& arr)
    {
        int n=(int)arr.size();
        if(n==1)
        {
            return 0;
        }
        unordered_map<int,vector<int>> list;
        for(int i=0;i<n;i++)
        {
            list[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        bitset<50000> visited;
        visited.set(0);
        int cnt=0;
        while(!q.empty())
        {
            int m=(int)q.size();
            for(int i=0;i<m;i++)
            {
                int cur=q.front();
                q.pop();
                if(cur==n-1)
                {
                    return cnt;
                }
                if(list.count(arr[cur]))
                {
                    for(int next:list[arr[cur]])
                    {
                        if(visited.test(next)==false)
                        {
                            q.push(next);
                            visited.set(next);
                        }
                    }
                    list.erase(arr[cur]);
                }
                if(cur+1<n&&visited.test(cur+1)==false)
                {
                    q.push(cur+1);
                    visited.set(cur+1);
                }
                if(cur-1>=0&&visited.test(cur-1)==false)
                {
                    q.push(cur-1);
                    visited.set(cur-1);
                }
            }
            cnt++;
        }
        return -1;
    }
};
