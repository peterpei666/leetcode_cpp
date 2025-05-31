#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n=(int)board.size();
        int minroll[n*n+1];
        memset(minroll,-1,sizeof(minroll));
        queue<int> q;
        q.push(1);
        minroll[1]=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=1;i<=6&&i+x<=n*n;i++)
            {
                int next=x+i;
                int row=(next-1)/n;
                int col=(next-1)%n;
                int temp=board[n-1-row][row%2?n-1-col:col];
                if(temp!=-1)
                {
                    next=temp;
                }
                if(next==n*n)
                {
                    return minroll[x]+1;
                }
                if(minroll[next]==-1)
                {
                    minroll[next]=minroll[x]+1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
