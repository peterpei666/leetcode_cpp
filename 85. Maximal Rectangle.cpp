#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int r=(int)matrix.size();
        int c=(int)matrix[0].size();
        vector<int> height(c+1,0);
        int ans=0;
        for(auto& row:matrix)
        {
            for(int i=0;i<c;i++)
            {
                if(row[i]=='1')
                {
                    height[i]++;
                }
                else
                {
                    height[i]=0;
                }
            }
            stack<int> stk;
            stk.push(-1);
            for(int i=0;i<=c;i++)
            {
                while(stk.top()!=-1&&height[i]<=height[stk.top()])
                {
                    int h=height[stk.top()];
                    stk.pop();
                    int w=i-stk.top()-1;
                    ans=max(ans,w*h);
                }
                stk.push(i);
            }
        }
        return ans;
    }
};
