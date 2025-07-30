#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int cnt;
    
    bool valid(char list[9],int m,int x)
    {
        for(int i=0;i<m;i++)
        {
            if(x==list[i]||abs(m-i)==abs(x-list[i]))
            {
                return false;
            }
        }
        return true;
    }
    
    void place(char list[9],int m,int n)
    {
        if(m==n)
        {
            cnt++;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(valid(list,m,i))
                {
                    list[m]=i;
                    place(list,m+1,n);
                }
            }
        }
    }
    
public:
    int totalNQueens(int n)
    {
        char list[9];
        cnt=0;
        place(list,0,n);
        return cnt;
    }
};
