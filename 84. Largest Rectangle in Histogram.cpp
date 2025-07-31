#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> stk;
        stk.push(-1);
        int ans=0;
        int n=(int)heights.size();
        for(int i=0;i<n;i++)
        {
            while(stk.top()!=-1&&heights[stk.top()]>=heights[i])
            {
                int h=heights[stk.top()];
                stk.pop();
                int w=i-stk.top()-1;
                ans=max(ans,h*w);
            }
            stk.push(i);
        }
        while (stk.top()!=-1)
        {
            int h=heights[stk.top()];
            stk.pop();
            int w=n-stk.top()-1;
            ans=max(ans,h*w);
        }
        return ans;
    }
};
