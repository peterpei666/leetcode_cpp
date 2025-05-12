#include <iostream>
#include <algorithm>
#include <bitset>
#include <stack>
using namespace std;

class Solution
{
public:
    bool canMeasureWater(int x, int y, int target)
    {
        if(x+y<target)
        {
            return false;
        }
        bitset<1001> visited[x+1];
        stack<pair<int,int>> p;
        p.push({0,0});
        p.push({x,y});
        p.push({x,0});
        p.push({0,y});
        while(!p.empty())
        {
            auto [a,b]=p.top();
            p.pop();
            if(visited[a].test(b))
            {
                continue;
            }
            visited[a].set(b);
            if(a+b==target)
            {
                return true;
            }
            int w;
            w=min(a,y-b);
            p.push({a-w,b+w});
            w=min(x-a,b);
            p.push({a+w,b-w});
            p.push({x,b});
            p.push({a,y});
            p.push({a,0});
            p.push({0,b});
        }
        return false;
    }
};
