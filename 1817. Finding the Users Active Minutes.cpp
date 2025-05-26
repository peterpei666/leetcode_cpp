#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k)
    {
        sort(logs.begin(),logs.end(),[](const vector<int>& a,const vector<int>& b){ return a[0]==b[0]?a[1]<b[1]:a[0]<b[0]; });
        int list[logs.size()];
        memset(list,0,sizeof(list));
        int cur=-1,m=-1;
        for(int i=0;i<logs.size();i++)
        {
            if(i&&logs[i][0]==logs[i-1][0]&&logs[i][1]==logs[i-1][1])
            {
                continue;
            }
            else
            {
                if(cur==-1||cur!=logs[i][0])
                {
                    cur=logs[i][0];
                    m++;
                }
                list[m]++;
            }
        }
        vector<int> ans(k,0);
        for(int i=0;i<=m;i++)
        {
            if(list[i]&&list[i]-1<k)
            {
                ans[list[i]-1]++;
            }
        }
        return ans;
    }
};
