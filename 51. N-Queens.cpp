#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool valid(vector<string>& board,int r,int c,int n)
    {
        for(int i=0;i<r;i++)
        {
            if(board[i][c]=='Q')
            {
                return false;
            }
        }
        for(int i=r,j=c;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i=r,j=c;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    
    void construct(vector<vector<string>>& ans,vector<string>& board,int r,int n)
    {
        if(r==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(valid(board,r,i,n))
            {
                board[r][i]='Q';
                construct(ans,board,r+1,n);
                board[r][i]='.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        construct(ans,board,0,n);
        return ans;
    }
};
