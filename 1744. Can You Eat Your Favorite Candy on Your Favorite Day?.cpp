#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries)
    {
        int n=(int)candiesCount.size();
        vector<long long> prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+candiesCount[i];
        }
        n=(int)queries.size();
        vector<bool> ret(n);
        for(int i=0;i<n;i++)
        {
            if(queries[i][1]+1<=prefix[queries[i][0]+1]&&(long long)(queries[i][1]+1)*queries[i][2]>prefix[queries[i][0]])
            {
                ret[i]=true;
            }
            else
            {
                ret[i]=false;
            }
        }
        return ret;
    }
};

