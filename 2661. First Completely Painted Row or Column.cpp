#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int m=(int)mat.size();
        int n=(int)mat[0].size();
        int list[m*n+1];
        for(int i=0;i<m*n;i++)
        {
            list[arr[i]]=i;
        }
        int ans1=m*n,ans2=m*n;
        for(int i=0;i<m;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            {
                temp=max(temp,list[mat[i][j]]);
            }
            ans1=min(ans1,temp);
        }
        for(int j=0;j<n;j++)
        {
            int temp=0;
            for(int i=0;i<m;i++)
            {
                temp=max(temp,list[mat[i][j]]);
            }
            ans2=min(ans2,temp);
        }
        return min(ans1,ans2);
    }
};
