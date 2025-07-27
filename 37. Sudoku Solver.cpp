#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool valid(vector<vector<char>>& board,int r,int c,int num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[r][i]=='0'+num||board[i][c]=='0'+num)
            {
                return false;
            }
        }
        int x=r-r%3;
        int y=c-c%3;
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(board[i][j]=='0'+num)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<char>>& board,int r,int c)
    {
        if(r==9)
        {
            return true;
        }
        if(c==9)
        {
            return dfs(board,r+1,0);
        }
        if(board[r][c]=='.')
        {
            for(int i=1;i<=9;i++)
            {
                if(valid(board,r,c,i))
                {
                    board[r][c]='0'+i;
                    if(dfs(board,r,c+1))
                    {
                        return true;
                    }
                    board[r][c]='.';
                }
            }
        }
        else
        {
            return dfs(board,r,c+1);
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        dfs(board,0,0);
    }
};
